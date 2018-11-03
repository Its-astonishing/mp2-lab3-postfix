#include "postfix.h"
#include "stack.h"

short int TPostfix::prior(string str)
{
    short int prior = 0;
    char c = str[0];
    switch (c)
    {
    case '(':
        prior = 0;
        break;
    case (')'):
        prior = 1;
        break;
    case ('+'):
        prior = 2;
        break;
    case '-':
        prior = 2;
        break;
    case '*':
        prior = 3;
        break;
    case '/':
        prior = 3;
        break;
    }
    return prior;
}

vector<string>TPostfix::splitInfix(const string& str)
{
    string buf;
    vector<string> res;
    size_t npos = -1;
    for (char c : str)
    {
        if (c == ' ')
            continue;
        if (operations.find(c) == npos)
            buf += c;
        else
        {
            if (!buf.empty())
                res.push_back(buf);
            buf = c;
            res.push_back(buf);
            buf.clear();
        }

    }
    if (!buf.empty())
        res.push_back(buf);
    return res;
}
vector<string>TPostfix::splitPostfix(const string& str)
{
    string buf;
    vector<string> res;
    size_t npos = -1;
    for (char c : str)
    {
        if (operations.find(c) == npos)
            if (c == ' ')
            {
                if (!buf.empty())
                    res.push_back(buf);
                buf.clear();
            }
            else
                buf += c;
        else
        {
            if (!buf.empty())
                res.push_back(buf);
            buf = c;
            res.push_back(buf);
            buf.clear();
        }

    }
    if (!buf.empty())
        res.push_back(buf);
    return res;
}
double TPostfix::calculateOperands(string str, double op1, double op2)
{
    char c = str[0];
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
}
double TPostfix::inputVar(const string& str)
{
    double res;
    cout << "\t" << str << "=";
    cin >> res;
    return res;
}
bool TPostfix::isNum(const string& str)
{
    for (char c : str)
        if (c < 48 || c>57)
            return 0;
    return 1;
}
bool TPostfix::isOperation(char c)
{
    size_t npos = -1;
    if (operations.find(c) == npos || operations.find(c) == 4 || operations.find(c) == 5)
        return 0;
    return 1;
}
bool TPostfix::isCorrect(const string& str)
{
    int counter = 0;
    size_t npos = -1;
    if (isOperation(str[0]) || isOperation(str[str.size() - 1]))
        return 0;
    if (str[0] == '(')
        counter++;
    if (str[0] == ')')
        counter--;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '(')
            counter++;
        if (str[i] == ')')
            counter--;
        if (isOperation(str[i]) && isOperation(str[i - 1]))
            return 0;
    }
    if (counter == 0)
        return 1;
    else
        return 0;
}
void TPostfix::toPostfix(const string& str)
{
    if (!isCorrect(str))
        throw "error";
    postfix.clear();
    infix = str;
    vector<string> components = splitInfix(str);
    TStack <string> St;
    size_t npos = -1;
    for (string c : components)
        if (operations.find(c) != npos)
        {
            if (c != ")")
            {
                if (St.isEmpty() || prior(c) == 0 || prior(c) > prior(St.top()));
                else
                {
                    while (!St.isEmpty())
                        if (prior(St.top()) >= prior(c))
                        {
                            postfix += St.pop();
                            postfix += ' ';
                        }
                        else
                            break;
                }
                St.push_back(c);
            }
            else
            {
                int it = St.getSize();
                for (int i = 0; i < it; i++)
                    if (St.top() != "(")
                    {
                        postfix += St.pop();
                        postfix += ' ';
                    }
                    else
                    {
                        St.pop();
                        break;
                    }
            }
        }
        else
        {
            postfix += c;
            postfix += ' ';
        }
    while (!St.isEmpty())
    {
        postfix += St.pop();
        postfix += ' ';
    }
}
double TPostfix::calculate()
{
    if (postfix.empty())
        throw "error";
    vector<string> components = splitPostfix(postfix);
    size_t npos = -1;
    double res = 0;
    TStack<double> stack;
    double op2;
    double op1;
    double var;
    for (string c : components)
    {
        if (operations.find(c) == npos)
        {
            if (!isNum(c))
            {
                var = inputVar(c);
                stack.push_back(var);
            }
            else
                stack.push_back(stod(c));

        }
        else
        {
            op2 = stack.pop();
            op1 = stack.pop();
            stack.push_back(calculateOperands(c, op1, op2));
        }
    }
    return stack.pop();
}
string TPostfix::getPostfix()
{
    return postfix;
}
