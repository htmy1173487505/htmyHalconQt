#ifndef DOMCONNECTION_H
#define DOMCONNECTION_H

#include "superstruct.h"

class DomConnection : public SuperStruct
{
public:
    DomConnection();

    // SuperStruct interface
public:
    void action();
};

#endif // DOMCONNECTION_H
