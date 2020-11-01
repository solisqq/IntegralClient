#ifndef BITSMANIPULATORS_H
#define BITSMANIPULATORS_H
#include <QList>
#include <QByteArray>
#include <QDebug>
namespace BitsManipulator
{

//QList<int> getSetBitsFromArr(QByteArray&);
template<typename Type>
bool isSet(Type val, int pos) {
    return (val &(1<<(pos-1)));
}
template<typename Type>
QList<int> getSetBits(Type val) {
    QList<int> toRet;
    for(int i=0; i<static_cast<int>(sizeof(Type)); i++)
        if(isSet<Type>(val, i))
            toRet.append(i);
    return toRet;
}

inline QList<int> getSetBitsFromArr(QByteArray &arr, bool invert=false) { //Returns List of ints where every ints is information which bit of byte array was true
    //0100 0000 0010 0000 1000 0000
    QList<int> toRet;
    for(int i=0; i<arr.count(); i++) {
        for(int j=0; j<8; j++) {
            if(isSet(arr[i], j)) {
                toRet.append((i*8)+ (invert? 8-j:j));
            }
        }
    }
    return toRet;
}

inline QByteArray get16BArrayFromList(QList<int> list) { //Returns two-byte array from list, where list contains elements in range 0-15. List sets which bit should be true in array
    QByteArray toRet;
    for(int i=1; i<=16; i++) {
        unsigned char toAdd = 0x00;
        foreach(int listInt, list) {
            if(listInt<i*8) {
                toAdd^=listInt-((i-1)*8);
                list.removeOne(listInt);
            }
        }
        toRet.append(toAdd);
    }
    return toRet;
}

inline QByteArray get4BArrayFromList(QList<int> list) { //Returns two-byte array from list, where list contains elements in range 0-15. List sets which bit should be true in array
    QByteArray toRet;
    for(int i=1; i<=4; i++) {
        unsigned char toAdd = 0x00;
        foreach(int listInt, list) {
            if(listInt<i*8) {
                toAdd|= (1UL << (listInt-((i-1)*8)));
                list.removeOne(listInt);
            }
        }
        toRet.append(toAdd);
    }
    qDebug()<<toRet;
    return toRet;
}

}

#endif // BITSMANIPULATOR_H
