#ifndef TINYINPUT_H
#define TINYINPUT_H

#include <QWidget>

namespace Ui {
class TinyInput;
}

class TinyInput : public QWidget
{
    Q_OBJECT
    int cid=0;
public:
    explicit TinyInput(int id, QWidget *parent = nullptr);
    ~TinyInput();
    void setID(int id);
    int getID();
    bool getState();
    void setState(bool);

private:
    Ui::TinyInput *ui;
};

#endif // TINYINPUT_H
