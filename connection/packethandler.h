#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include <QWidget>

namespace Ui {
class PacketHandler;
}

class PacketHandler : public QWidget
{
    Q_OBJECT

public:
    explicit PacketHandler(QWidget *parent = nullptr);
    ~PacketHandler();

private:
    Ui::PacketHandler *ui;
};

#endif // PACKETHANDLER_H
