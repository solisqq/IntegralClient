#include "packet.h"
#include <QDebug>
#include <dialogs/infodialog.h>
Packet::Packet(IntegralCommand *command, QObject *parent, bool deleteAfter): QObject(parent), cmd(command), deleteAfterResponse(deleteAfter)
{
    header.append(static_cast<char>(0xFE));
    header.append(static_cast<char>(0xFE));
    footer.append(static_cast<char>(0xFE));
    footer.append(static_cast<char>(0x0D));
    connect(&timeoutTimer, &QTimer::timeout, this, &Packet::timeoutHandler);
    timeoutTimer.setInterval(settings.packetTimeout.get());
    /*if(command->isWritable()) {
        if() {
            //connect()
        }
    }*/
}

QByteArray Packet::getBytes()
{
    QByteArray toRet;
    QByteArray frame = cmd->getFullFrame();
    frame.append(calculateCRC(frame));
    frame = expandForSpecialValue(frame);

    toRet.append(header);
    toRet.append(frame);
    toRet.append(footer);
    timeoutTimer.start();
    return toRet;
}

char Packet::getCode()
{
    if(cmd->isWritable()) return static_cast<char>(0xEF);
    return cmd->getCode();
}

QString Packet::getCmdName()
{
    return cmd->getName();
}

int Packet::getResponseLength()
{
    return cmd->getResponseLength();
}

void Packet::responseReady(QByteArray &arr) {
    emit( getResponse( cmd->parseResponse(arr) ) );
    if(cmd->isWritable() && cmd->isDialogDataValid()) {
        InfoDialog* dialog;
        if(arr.at(0)==0 || arr.at(0)==static_cast<char>(0xFF))
            dialog = new InfoDialog(InfoDialog::Info, cmd->getSuccess().at(0), cmd->getSuccess().at(1), nullptr, true);
        else
            dialog = new InfoDialog(InfoDialog::Warning, cmd->getFailure().at(0), cmd->getFailure().at(1), nullptr, true);
        dialog->show();
    }
    timeoutTimer.stop();
    if(deleteAfterResponse) delete this;
}

void Packet::timeoutHandler()
{
    //auto dialog = new InfoDialog(InfoDialog::Warning, "Zgubiono pakiet", "Jeden z pakietów danych nie dotarł do serwera, bądź serwer nie odpowiedział. Sprawdź połączenie.");
    //dialog->show();
    timeoutTimer.stop();
    emit(timeout(this));
}

Packet::~Packet()
{
    delete cmd;
}

QByteArray Packet::calculateCRC(const QByteArray &arr)
{
    unsigned short crc = 0x147A;

    for (int i = 0; i < arr.length(); ++i)
    {
        crc = (crc << 1) | (crc >> 15);
        crc = crc ^ 0xFFFF;
        crc = crc + (crc >> 8) + static_cast<unsigned char>(arr.at(i));
    }
    QByteArray toReturn;
    toReturn.append((crc >> 8));
    toReturn.append(crc & 0xFF);
    return toReturn;
}
QByteArray Packet::expandForSpecialValue(QByteArray &toEdit)
{
    QByteArray result;
    result.append(toEdit);
    char specialValue = static_cast<char>(0xFE);

    for(int i=0; i<result.count(); i++) {
        if(result.at(i)==specialValue) {
            result.insert(i+1, static_cast<char>(0xF0));
        }
    }
    return result;
}
