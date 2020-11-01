#ifndef FASTVIEW_H
#define FASTVIEW_H

#include <QWidget>

namespace Ui {
class FastView;
}

class FastView : public QWidget
{
    Q_OBJECT

public:
    explicit FastView(QWidget *parent = nullptr);
    ~FastView();

private:
    Ui::FastView *ui;
};

#endif // FASTVIEW_H
