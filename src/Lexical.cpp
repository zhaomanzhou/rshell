//
// Created by zmz on 19-3-2.
//

#include <sstream>
#include <algorithm>
#include "Lexical.h"

const string &Lexical::getInput() const {
    return input;
}

void Lexical::setInput(const string &input) {
    Lexical::input = input;
    tokens.clear();
}

const vector<string> &Lexical::getTokens() const {
    return tokens;
}

vector<string> &Lexical::lexicalPaser() {
    tokens.clear();
    unsigned long i1 = input.find("\"");
    while (i1 != string::npos)
    {
        unsigned long i2 = input.find("\"", i1+1);
        for(int i = i1; i < i2; i++)
        {
            if(input[i] == ' ')
                input[i] = '^';

        }
        i1 = input.find("\"", i2+1);
    }

    istringstream ss(input);
    string s;
    while (!ss.eof())
    {
        ss>>s;


        if(s[0] == '\"')
        {
            replace(s.begin(), s.end(), '^', ' ');
            replace(s.begin(), s.end(), '\"', '\0');
            s.erase(0, 1);
            //s.erase(s.size()-1, 1);
            //tokens.push_back(s);
        }

        if(s[s.size() - 1] == ';')
        {
            tokens.push_back(s.substr(0, s.size() -1));
            tokens.push_back(";");
        }

        else if(s.find(")") != string::npos)
        {
            unsigned long i = s.find(")");
            tokens.push_back(s.substr(0, i));
            s = s.substr(i);
            int index = 0;
            for(; index < s.length(); index++)
            {
                tokens.push_back(")");
            }

        }

        else if(s[0] == '(')
        {
            while (s[0] == '(')
            {
                tokens.push_back("(");
                s.erase(0, 1);
            }
            tokens.push_back(s);
        }else
        {
                tokens.push_back(s);
        }


    }
    return tokens;
}

void Lexical::cleanAnnotation() {
    bool jump = false;
    int i;
    for(i = 0; i < input.size(); i++)
    {
        if(input[i] == '\"')
            jump = !jump;
        if(!jump && input[i] == '#')
            break;
    }
    input = input.substr(0, i);
}

Lexical::Lexical(const string &input) : input(input) {
    cleanAnnotation();
}

Lexical::Lexical() {}





Grammer::Grammer(const vector<string> &tokens) : tokens(tokens) {}

void Grammer::paser() {
    vector<string> v;
    bool mult = false;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "(")
        {
            mult = true;
            continue;
        }else if (tokens[i] == ")")
        {
            mult = false;
            if(!v.empty())
                commands.push_back(new MultiCommand(v));
            v.clear();
            continue;
        }

        if(mult)
        {
            v.push_back(tokens[i]);
        }else
        {
            if(isConnector(tokens[i]))
            {
                if(!v.empty())
                    commands.push_back(new SimpleCommand(v));
                connectors.push_back(getConnectorByToken(tokens[i]));
                v.clear();
            } else
            {
                v.push_back(tokens[i]);
            }
        }
    }
    if(!v.empty())
    {
        commands.push_back(new SimpleCommand(v));
    }

}

void Grammer::execute() {
    paser();
    int result = 0;
    for(int i = 0; i < commands.size(); i++)
    {
        int result = commands[i]->execute();
        if(connectors.size() > i)
        {
            bool b = connectors[i]->ternimal(result);
            if(b)
            {
                i++;
            }

        }
    }
    for(int i = 0; i < connectors.size(); i++)
    {
        delete connectors[i];
    }
    for(int i = 0; i < commands.size(); i++)
    {
        delete commands[i];
    }

}

bool Grammer::isConnector(const std::string &s) {
    return s == "||" || s == "&&" || s == ";";
}


NewGrammer::NewGrammer(const vector<string> &tokens) {
    newMultiCommand = new NewMultiCommand(tokens);
}

void NewGrammer::execute() {
    newMultiCommand->execute();
}
