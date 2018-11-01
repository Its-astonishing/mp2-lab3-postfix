#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
    string expression;
    TPostfix postfix;
    vector<string> samples;
    samples.push_back("1+2");
    samples.push_back("1+2*(3-2)-4");
    samples.push_back("1+2/(3-3)");
    samples.push_back("10+2002*400-12");
    samples.push_back("a+b");
    for (string c : samples)
    {
        cout << "Normal form:" << endl << c << endl;
        postfix.toPostfix(c);
        cout << "Postfix form:" << endl << postfix.getPostfix() << endl;
        cout << "Calculation:" << endl << postfix.calculate() << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}
