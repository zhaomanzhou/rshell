#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>

class Connector
{
    public:
    virtual bool ternimal(int prevReturnValue)
    {
        return false;
    }

    virtual bool isOr()
    {
        return false;
    }
    
    protected:
    int prevReturnValue = 0;

};


class SemicolonConnector: public Connector
{
    virtual bool ternimal(int prevReturnValue)
    {
        return false;
    }
};


class AndConnector: public Connector
{
public:
    virtual bool ternimal(int prevReturnValue)
    {
        return prevReturnValue != 0;
    }

};



class OrConnector: public Connector
{
public:
    virtual bool ternimal(int prevReturnValue)
    {
        if(prevReturnValue == 0)
        {
            return true;
        }
        return false;
    }

    bool isOr() override {
        return true;
    }
};


Connector *getConnectorByToken(std::string& token);

#endif
