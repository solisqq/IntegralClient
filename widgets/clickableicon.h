#ifndef CLICKABLEICON_H
#define CLICKABLEICON_H

#include <QWidget>

namespace Ui {
class ClickableIcon;
}

class ClickableIcon : public QWidget
{
    Q_OBJECT
    QString hoverColor="#2d2d2d";
    QString textColor="";
    QString textSize="";
    QString fontWeight="400";

public:
    explicit ClickableIcon(QWidget *parent = nullptr);
    ClickableIcon(const QString &iconRsrc, QWidget *parent=nullptr, const QString &text="", const QString &colorInHexWithSlash="#282828", const QString &_textColor="#cccccc", const QString &_textSize="11");
    ~ClickableIcon() override;

    void setIcon(const QString& src);
    void setText(const QString& src);

    QString getHoverColor() const;
    void setHoverColor(const QString &value);

    QString getTextColor() const;
    void setTextColor(const QString &value);

    QString getTextSize() const;
    void setTextSize(const QString &value);

    void updateView();
    void setup(const QString &iconRsrc, const QString &text="", const QString &colorInHexWithSlash="#282828", const QString &_textColor="#cccccc", const QString &_textSize="11");
    void setFontWeight(const QString &value);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

signals:
    void mouseLeave();
    void mouseEnter();
    void clicked();

private:
    Ui::ClickableIcon *ui;

};

#endif // CLICKABLEICON_H
