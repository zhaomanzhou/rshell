//
// Created by zmz on 19-3-2.
//

#ifndef ULEXICAL_LEXICAL_H
#define ULEXICAL_LEXICAL_H

#include <vector>
#include <string>
#include "Command.h"
#include "Connector.h"

using namespace std;

class Lexical {
private:
    string input;
    vector<string> tokens;
    void cleanAnnotation();

public:
    Lexical();

    Lexical(const string &input);

    const string &getInput() const;

    void setInput(const string &input);

    const vector<string> &getTokens() const;

    vector<string> &lexicalPaser();

};


class Grammer{
private:
    vector<Command*> commands;
    vector<Connector*> connectors;
    vector<string> tokens;
    void paser();
    void paser1(vector<string>& token);
    bool isConnector(const std::string& s);

public:
    Grammer(const vector<string> &tokens);
    void execute();
};


class NewGrammer{
private:
    vector<string> tokens;
    NewMultiCommand* newMultiCommand;

public:
    NewGrammer(const vector<string> &tokens);
    void execute();
};



#endif //ULEXICAL_LEXICAL_H
