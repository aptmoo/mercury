#ifndef SHARED_APPINTERFACE_H
#define SHARED_APPINTERFACE_H

class IAppInterface
{
public:
    virtual ~IAppInterface() = default;

    virtual void TestPrint() = 0;
};

#endif