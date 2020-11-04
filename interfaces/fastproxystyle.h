#ifndef FASTPROXYSTYLE_H
#define FASTPROXYSTYLE_H

#include <QProxyStyle>
class FastProxyStyle : public QProxyStyle
{
public:
    using QProxyStyle::QProxyStyle;
    int styleHint(StyleHint hint, const QStyleOption* option = nullptr, const QWidget* widget = nullptr, QStyleHintReturn* returnData = nullptr) const override
    {
        if (hint == QStyle::SH_ToolTip_WakeUpDelay)
            return 1000;
        return QProxyStyle::styleHint(hint, option, widget, returnData);
    }
};

#endif // FASTPROXYSTYLE_H
