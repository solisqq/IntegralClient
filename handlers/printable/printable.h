#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <QString>

class PrintAble
{
public:
    virtual QString getString()=0;
    virtual ~PrintAble(){}
};

#endif // PRINTABLE_H
