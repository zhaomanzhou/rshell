#include "gtest/gtest.h"
#include "../src/Lexical.h"
#include "../src/Command.h"
#include "../src/Connector.h"
#include "../src/Lexical.h"

//TEST(TokenListTest, TestCleanAnnotation)
//{
//    TokenList tl("ls -al# pwd");
//    ASSERT_EQ(tl.getInput(), "ls -al");
//}
//
//TEST(TokenListTest, TestTokenInput)
//{
//    TokenList tl("ls -al && echo hello; git status");
//    vector<string> v;
//    v.push_back("ls -al");
//    v.push_back(" &");
//    v.push_back("echo hello");
//    v.push_back("; ");
//    v.push_back("git status");
//    ASSERT_EQ(v, tl.tokenInput());
//}
//
TEST(TestCommand, TestExitCommand)
{
    Command* c;
    c = new ExitCommand();
    //ASSERT_EQ(c->execute(), true);
}

TEST(TestCommand, TestSimpleCommand)
{
    Command* c;
    vector<string> v;
    v.push_back("ls");
    v.push_back("-a");
    c = new SimpleCommand(v);
    ASSERT_EQ(c->execute(), 0);
}

TEST(TestConnector, TestSemicolonConnector)
{
    string s(";");
    Connector *c = getConnectorByToken(s);
    ASSERT_EQ(c->ternimal(0), false);
    ASSERT_EQ(c->ternimal(1), false);
}


TEST(TestConnector, TestAndlonConnector)
{
    string s("&&");
    Connector *c = getConnectorByToken(s);
    ASSERT_EQ(c->ternimal(0), false);
    ASSERT_EQ(c->ternimal(1), true);
}

TEST(TestConnector, TestOrConnector)
{
    string s("||");
    Connector *c = getConnectorByToken(s);
    ASSERT_EQ(c->ternimal(0), true);
    ASSERT_EQ(c->ternimal(1), false);
}


//TEST(Testparentheses, Testparentheses1)
//{
//    TokenList tl("(echo A && echo B) || (echo C && echo D)");
//    vector<string> v;
//    v.push_back("echo A && echo B");
//    v.push_back(" |");
//    v.push_back("echo C && echo D");
//    ASSERT_EQ(v, tl.tokenInputWithBracket());
//}
//
//TEST(Testparentheses, Testparentheses2)
//{
//    TokenList tl("(echo A && echo B) || echo C && echo D && (echo e || echo d)");
//    vector<string> v;
//    v.push_back("echo A && echo B");
//    v.push_back(" |");
//    v.push_back("echo C");
//    v.push_back(" &");
//    v.push_back("echo D");
//    v.push_back(" &");
//    v.push_back("echo e || echo d");
//    ASSERT_EQ(v, tl.tokenInputWithBracket());
//}



TEST(TestCommand, simpleCommand)
{
    Command* command;
    {

        vector<string> v;
        v.push_back("ls");
        v.push_back("-al");
        command = new SimpleCommand(v);
    }
    int i = command->execute();
    cout<<i;
}


TEST(TestLexical, Test)
{
    Lexical l("ls -al; ps aux");
    vector<string> &vector = l.lexicalPaser();
    for(int i = 0; i < vector.size(); i++)
    {
        cout<<vector[i]<<endl;
    }

    
}

TEST(Testexecp, TestMultiEcho)
{
    string s1("echo");
    string s2("a");
    string s3("a");

    char** cmd = new char*[4];
    cmd[0] = const_cast<char *>(s1.c_str());
    cmd[1] = const_cast<char *>(s2.c_str());
    cmd[2] = const_cast<char *>(s2.c_str());
    cmd[3] = NULL;
    int stat;
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execvp(s1.c_str(), cmd);
        //perror("execvp failed");
        //exit(1);
    }
    wait(&stat);

}


TEST(Testexecp, TestSingleEcho)
{
    string s1("echo");
    string s2("a");

    char** cmd = (char**)malloc(sizeof(char*)*3);
    cmd[0] = const_cast<char *>(s1.c_str());
    cmd[1] = const_cast<char *>(s2.c_str());

    int stat;
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execvp(s1.c_str(), cmd);
        //perror("execvp failed");
        //exit(1);
    }
    wait(&stat);

}

TEST(Testexecp, TestMultArgs)
{
    string s1("ls");
    string s2("-a");
    string s3("-l");

    char* cmd[4];

    cmd[0] = const_cast<char *>(s1.c_str());
    cmd[1] = const_cast<char *>(s2.c_str());
    cmd[2] = const_cast<char *>(s3.c_str());
    int stat;
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        //execvp("ls", cmd);
        //perror("execvp failed");
        //exit(1);
    }
    wait(&stat);

}




TEST(Testexecp, TestNewString2)
{
//    char * argv[] = {"ls", "-al", "/etc/passwd", 0};
    //execvp("ls", argv);

}

TEST(Testexecp, TestMultiEcho2)
{
    string s1("echo");
    string s2("a");
    string s3("a");

    char** cmd = new char*[3];
    cmd[0] = const_cast<char *>(s1.c_str());
    cmd[1] = const_cast<char *>(s2.c_str());
    cmd[2] = const_cast<char *>(s2.c_str());
    int stat;
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execvp(s1.c_str(), cmd);
        //perror("execvp failed");
        //exit(1);
    }
    wait(&stat);

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
