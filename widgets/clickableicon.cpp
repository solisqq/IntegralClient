#include "clickableicon.h"
#include "ui_clickableicon.h"
void ClickableIcon::setFontWeight(const QString &value)
{
    fontWeight = value;
    updateView();
}

ClickableIcon::ClickableIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClickableIcon)
{
    ui->setupUi(this);
}

ClickableIcon::ClickableIcon(const QString& iconRsrc, QWidget *parent, const QString& text, const QString& colorInHexWithSlash, const QString& _textColor, const QString& _textSize):
    QWidget(parent),
    ui(new Ui::ClickableIcon)
{
    ui->setupUi(this);
    setup(iconRsrc,text,colorInHexWithSlash,_textColor,_textSize);
}

ClickableIcon::~ClickableIcon() {}

QString ClickableIcon::getHoverColor() const
{
    return hoverColor;
}

void ClickableIcon::setHoverColor(const QString& value)
{
    hoverColor = value;
}

void ClickableIcon::setup(const QString& iconRsrc, const QString& text, const QString& colorInHexWithSlash, const QString& _textColor, const QString& _textSize)
{
    setHoverColor(colorInHexWithSlash);
    setIcon(iconRsrc);
    setText(text);
    setTextColor(_textColor);
    setTextSize(_textSize);
    updateView();
}
void ClickableIcon::updateView() {
    setStyleSheet("#centralWidg { "
                  "background-color:none;"
                  "font-size: "+textSize+";"
                  "color: "+textColor+";"
                  "font-weight:+"+fontWeight+";"
                  "}"
                  "#centralWidg::hover { background-color:"+hoverColor+";}"
                  );
}

void ClickableIcon::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QWidget::mousePressEvent(event);
}
QString ClickableIcon::getTextColor() const
{
    return textColor;
}

void ClickableIcon::setTextColor(const QString& value)
{
    textColor = value;
}

QString ClickableIcon::getTextSize() const
{
    return textSize;
}

void ClickableIcon::setTextSize(const QString& value)
{
    textSize = value;
    updateView();
}

void ClickableIcon::setIcon(const QString& src)
{
    this->ui->pixmapLabel->setPixmap(src);
}

void ClickableIcon::setText(const QString& src)
{
    this->ui->textLabel->setText(src);
}

void ClickableIcon::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}

void ClickableIcon::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    emit(mouseEnter());
}

void ClickableIcon::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    emit(mouseLeave());
}
