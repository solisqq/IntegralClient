#ifndef COPYPROTECTION_H
#define COPYPROTECTION_H

#include <QString>



class CopyProtection
{
public:
    static QString unhash(QString target, bool switchMult=false);
    static QString hash(QString target, int &mult1, int &mult2);
};

#endif // COPYPROTECTION_H
