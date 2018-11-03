#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <vector>
#include <iostream>
#include "stack.h"

using namespace std;

class TPostfix
{
    const string operations = "+-*/()";
    short int prior(string str);
    vector<string> splitInfix(const string& str);
    vector<string> splitPostfix(const string& str);
    double calculateOperands(string str, double op1, double op2);
    double inputVar(const string& str);
    bool isNum(const string& str);
    bool isOperation(char c); // is c + or - or * or /
    string postfix;
    string infix;
public:
    TPostfix() {}
    bool isCorrect(const string& str);
    void toPostfix(const string& str);
    string getPostfix();
    double calculate();
};

#endif
