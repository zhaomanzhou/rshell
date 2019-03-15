#include <iostream>
#include <string.h>
#include "Lexical.h"


using namespace std;





int debug = 0;
int main(int argc, char* argv[], char* envp[])
{
    string input;
    cout << "$ ";

    Lexical l;

    while(true)
    {
        getline(cin, input);

        if(input.empty())
        {
            cout << "$ ";
            continue;
        }
        l.setInput(input);
        vector<string> &v = l.lexicalPaser();
//        Grammer grammer(v);
//
//        grammer.execute();
        NewGrammer newGrammer(v);
        newGrammer.execute();
        cout << "$ ";
    }

    return 0;
}


