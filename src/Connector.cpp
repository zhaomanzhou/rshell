
#include "Connector.h"

Connector *getConnectorByToken(std::string& token)
{
    if(token == ";")
    {
        return new SemicolonConnector();
    }
    if(token == "||")
    {
        return new OrConnector();
    }
    if(token == "&&")
    {
        return new AndConnector();
    }
    return NULL;
}
