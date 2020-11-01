#include "errorable.h"

ErrorAble::ErrorAble() {}
void ErrorAble::generateError(Error &err){
    if(errors.lastIndexOf(&err)!=-1) {
        if(err.lifetime>0) err.currentLifeTime = err.lifetime;
        return;
    }
    err.dateAnnouced = QDateTime::currentDateTime();
    errors.append(&err);
}
void ErrorAble::cancelError(Error &err){
    err.noticed=false;
    //err.clicked=false;
    errors.removeOne(&err);
}

bool ErrorAble::errorExist(Error &err)
{
    return (errors.indexOf(&err)!=-1);
}

void ErrorAble::resetErrors()
{
    foreach(Error *err, errors) {
        cancelError(*err);
    }
}
