#include "Command.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

using namespace std;

int ExitCommand::execute()
{
    cout << "bye" << endl;
    exit(EXIT_SUCCESS);
}


int SimpleCommand::execute()
{
    if(tokens[0] == "test")
    {
        TestCommand tm(this->tokens);
        return tm.execute();

    }

    if(tokens[0] == "exit")
    {
        ExitCommand ec;
        return ec.execute();

    }


    return handleCommand();


    /*paser();
    int stat;
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execvp(path, cmd);
        perror("execvp failed");
        exit(1);
    }
    wait(&stat);
    delete[] cmd;
    return stat;*/
}


int SimpleCommand::handleCommand() {
    path = tokens[0].c_str();

}




SimpleCommand::SimpleCommand(const vector<string> &tokens) : tokens(tokens) {
    if(tokens[0] == "[")
    {
        this->tokens.pop_back();
        this->tokens[0] = "test";
    }
}

void SimpleCommand::paser() {
    path = tokens[0].c_str();
    cmd = new char*[tokens.size()+1];
    for(int i = 0; i < tokens.size(); i++)
    {
        cmd[i] = const_cast<char *>(tokens[i].c_str());
    }
    cmd[tokens.size()] = NULL;
}




void MultiCommand::paser() {
    vector<string> v;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(!isConnector(tokens[i]))
            v.push_back(tokens[i]);
        else
        {
            Command* c = new SimpleCommand(v);
            commands.push_back(c);
            v.clear();
            connectors.push_back(getConnectorByToken(tokens[i]));
        }
    }
    if(!v.empty())
        commands.push_back(new SimpleCommand(v));

}

bool MultiCommand::isConnector(const std::string &s) {
    return s == "||" || s == "&&" || s == ";";
}

MultiCommand::MultiCommand(const vector<string> &tokens) : tokens(tokens) {}

int MultiCommand::execute() {
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

    return result;
}

int TestCommand::execute() {
    if (tokens[1] == "-f")
        {
            struct stat buf;
            int i = stat(tokens[2].c_str(), &buf);
            if(i != 0)
            {
                printf("(False)\n");
                return -1;
            }

            if(S_ISREG(buf.st_mode))
            {
                printf("(True)\n");
                return 0;
            }else
            {
                printf("(False)\n");
                return -1;
            }
        }
        //checks if the file/directory exists and is a directory
        else if (tokens[1] == "-d")
        {
            struct stat buf;
            int i = stat(tokens[2].c_str(), &buf);
            if(i != 0)
            {
                printf("(False)\n");
                return -1;
            }
            if(S_ISDIR(buf.st_mode))
            {
                printf("(True)\n");
                return 0;
            }else
            {
                printf("(False)\n");
                return -1;
            }
        }
        //checks if the file/directory exists
        else
        {
            struct stat buf;
            int i = 0;
            if (tokens[1] == "-e")
            {
                i = stat(tokens[2].c_str(), &buf);
            }else
            {
                i = stat(tokens[1].c_str(), &buf);
            }
            if(i != 0)
            {
                printf("(False)\n");
                return -1;
            } else
            {
                printf("(True)\n");
                return 0;
            }
        }
}

TestCommand::TestCommand(const vector<string> &tokens) : tokens(tokens) {}





NewMultiCommand::NewMultiCommand(const std::vector<std::string> &tokens): tokens(tokens) {

}

int NewMultiCommand::execute() {
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

    return result;
}

void NewMultiCommand::paser()
{
    vector<string> v;
    int mult = 0;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "(")
        {
            mult++;
            if(mult == 1)
            {
                continue;
            }

        } else if (tokens[i] == ")")
        {
            mult--;
            if(mult == 0)
            {
                if (!v.empty())
                    commands.push_back(new NewMultiCommand(v));
                v.clear();
                continue;
            }
        }

        if (mult > 0)
        {
            v.push_back(tokens[i]);
        } else
        {
            if (isConnector(tokens[i])) {
                if (!v.empty())
                    commands.push_back(new SimpleCommand(v));
                connectors.push_back(getConnectorByToken(tokens[i]));
                v.clear();
            } else {
                v.push_back(tokens[i]);
            }
        }
    }
    if (!v.empty()) {
        commands.push_back(new SimpleCommand(v));
    }
}
bool NewMultiCommand::isConnector(const std::string &s) {
    return s == "||" || s == "&&" || s == ";";
}
