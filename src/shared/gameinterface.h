#ifndef SHARED_GAMEINTERFACE_H
#define SHARED_GAMEINTERFACE_H

class IGameInterface
{
public:
    virtual ~IGameInterface() = default;

    virtual void TestPrint() = 0;  
};

#endif