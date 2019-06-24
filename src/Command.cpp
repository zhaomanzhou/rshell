#include "Command.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

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
    paser();
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
    return stat;
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
                {
                    if(!containRedirect(v))
                        commands.push_back(new SimpleCommand(v));
                    else
                        commands.push_back(new RedirectCommand(v));
                }
                connectors.push_back(getConnectorByToken(tokens[i]));
                v.clear();
            } else {
                v.push_back(tokens[i]);
            }
        }
    }
    if (!v.empty()) {
        if(!containRedirect(v))
            commands.push_back(new SimpleCommand(v));
        else
            commands.push_back(new RedirectCommand(v));
    }
}
bool NewMultiCommand::isConnector(const std::string &s) {
    return s == "||" || s == "&&" || s == ";";
}

bool NewMultiCommand::containRedirect(const std::vector<std::string> &v) {
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == "|" || v[i] == "<" || v[i] == ">" || v[i] == ">>")
            return true;
    }
    return false;
}

RedirectCommand::RedirectCommand(const std::vector<std::string> &tokens): tokens(tokens) {

}

int RedirectCommand::execute() {
    int cmdNum = 1;
    vector<string> command;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "|")
        {
            cmdNum++;
            commands.push_back(command);
            command.clear();
        } else
        {
            command.push_back(tokens[i]);
        }

    }

    //the last command
    if(!command.empty())
    {
        commands.push_back(command);
    }

    int fd[cmdNum][2];
    for(int i = 0; i < cmdNum -1 ; i++)
    {
        pipe(fd[i]);
    }

    int processNum;
    for(processNum = 0; processNum < cmdNum; processNum++)
    {
        pid_t pid = fork();
        if(pid == 0)
            break;
    }

    for(int i = 0; i < cmdNum; i++)
    {
        if(processNum != i)
            continue;

        vector<string> &curVect = commands[i];
        //input and output redirect handle
        bool erase = false;
        for(vector<string>::iterator it = curVect.begin(); it != curVect.end(); )
        {

            if(erase)
            {
                curVect.erase(it);
                erase = false;
                continue;
            }else if(*it == "<")
            {

                int i1 = open((*(it + 1)).c_str(), O_RDONLY);
                dup2(i1, STDIN_FILENO);


                curVect.erase(it);
                erase = true;
            } else if(*it == ">")
            {
                int i1 = open((*(it + 1)).c_str(), O_CREAT | O_RDWR, 0755);
                dup2(i1, STDOUT_FILENO);
                curVect.erase(it);
                curVect.erase(it);
                break;
                erase = true;
            } else if(*it == ">>")
            {
                int i1 = open((*(it + 1)).c_str(), O_WRONLY | O_APPEND);


                dup2(i1, STDOUT_FILENO);
                curVect.erase(it);
                curVect.erase(it);
                break;
                erase = true;
            } else
            {
                it++;
            }
        }



        if(cmdNum == 1)
        {

        }
        else if(processNum == 0)
        {
            for(int index = 1; index < cmdNum - 1; index++)
            {
                close(fd[index][0]);
                close(fd[index][1]);
            }
            close(fd[i][0]);
            dup2(fd[i][1], STDOUT_FILENO);
        }
        else if(processNum == cmdNum -1)
        {
            for(int index = 0; index < cmdNum-2; index++)
            {
                if(index == i || index == i-1)
                    continue;
                close(fd[index][0]);
                close(fd[index][1]);
            }
            close(fd[i-1][1]);
            dup2(fd[i-1][0], STDIN_FILENO);
            close(fd[i][0]);
            close(fd[i][1]);
        }
        else
        {
            for(int index = 0; index < cmdNum-2; index++)
            {
                if(index == i || index == i-1)
                    continue;
                close(fd[index][0]);
                close(fd[index][1]);
            }
            close(fd[i-1][1]);
            dup2(fd[i-1][0], STDIN_FILENO);
            close(fd[i][0]);
            dup2(fd[i][1], STDOUT_FILENO);
        }

        char**  args = new char*[curVect.size() +1];
        for(int k = 0 ; k < curVect.size() ; k++)
        {
            args[k] = const_cast<char *>(curVect[k].c_str());
        }
        args[curVect.size()] = NULL;

        execvp(curVect[0].c_str(), args);
        perror("execvp failed");


    }



    for(int i = 0; i < cmdNum; i++)
    {
        close(fd[i][0]);
        close(fd[i][1]);
    }

    bool success = true;

    int stat[cmdNum];
    for(int l = 0; l < cmdNum; l++)
    {
        wait(&stat[l]);
        if(stat[l] != 0)
            success = false;
    }


    return success? 0: -1;
}
