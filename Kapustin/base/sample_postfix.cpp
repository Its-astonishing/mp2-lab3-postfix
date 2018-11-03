#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
    string expression;
    TPostfix postfix;
    vector<string> samples;
    samples.push_back("1+2/4/5-3");
    for (string c : samples)
    {
        cout << "Normal form:" << endl << c << endl;
        postfix.toPostfix(c);
        cout << "Postfix form:" << endl << postfix.getPostfix() << endl;
        cout << "Calculation:" << endl << postfix.calculate() << endl;
        cout << endl;
    }
    cout << "Input string to postfix and calculate it :" << endl;
    cin >> expression;
    postfix.toPostfix(expression);
    cout << endl << "Postfix form:" << endl << postfix.getPostfix() << endl;
    cout << "Calculation:" << endl << postfix.calculate() << endl;
    cout << endl;
    system("pause");
    return 0;
}
