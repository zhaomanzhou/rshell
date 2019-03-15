#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "Connector.h"

class Command
{
    public:
    virtual int execute()
    {
        return 0;
    }

    protected:
        const char* path;
        char** cmd;
        std::string s;
};

class ExitCommand: public Command
{
    public:
    int execute();
};

class SimpleCommand: public Command
{
public:
    SimpleCommand(const std::vector<std::string> &tokens);

    int execute();

private:
    const char* path;
    char** cmd;
    std::vector<std::string> tokens;
    void paser();

    int handleCommand();
};



class MultiCommand: public Command
{
public:
    MultiCommand(const std::vector<std::string> &tokens);

    int execute() override;

private:
    const char* path;
    char** cmd;
    std::vector<std::string> tokens;
    std::vector<Command*> commands;
    std::vector<Connector*> connectors;
    void paser();
    bool isConnector(const std::string& s);

};


class NewMultiCommand: public Command
{
public:
    NewMultiCommand(const std::vector<std::string> &tokens);

    int execute() override;

private:
    const char* path;
    char** cmd;
    std::vector<std::string> tokens;
    std::vector<Command*> commands;
    std::vector<Connector*> connectors;
    void paser();
    bool isConnector(const std::string& s);

};

class TestCommand: public Command
{
private:
    std::vector<std::string> tokens;
public:
    int execute() override;

    TestCommand(const std::vector<std::string> &tokens);
};





#endif
