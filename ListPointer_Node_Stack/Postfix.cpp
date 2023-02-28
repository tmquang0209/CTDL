#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

template <class T>
class Stack
{
private:
    T item[MAX];
    int size;

public:
    Stack()
    {
        size = 0;
    }

    void push(T newItem);
    void pop();
    void pop(T &stackTop);
    bool isEmpty() const
    {
        return (size == 0);
    }
    bool isFull() const
    {
        return (size == MAX);
    }
    T getTop() const;
    int getSize() const
    {
        return this->size;
    }
};

template <class T>
void Stack<T>::push(T newItem)
{
    if (!isFull())
    {
        item[size] = newItem;
        size++;
    }
    else
    {
        cout << "Push, mang day." << endl;
    }
}

template <class T>
void Stack<T>::pop()
{
    if (!isEmpty())
    {
        size--;
    }
    else
    {
        cout << "Pop, mang rong." << endl;
    }
}

template <class T>
void Stack<T>::pop(T &stackTop)
{
    if (!isEmpty())
    {
        stackTop = item[size - 1];
        size--;
    }
    else
    {
        cout << "PopT, mang rong." << endl;
    }
}

template <class T>
T Stack<T>::getTop() const
{
    return item[size - 1];
}

void postFix()
{
    Stack<char> c;
    string str;
    // str = "(a+b)/(c+d)";
    str = "a*(b+c)/d";
    string result;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            c.push(str[i]);
        else if (str[i] == ')')
        {
            while (c.getTop() != '(')
            {
                result += c.getTop();
                c.pop();
            }
            c.pop();
        }
        else
            result += str[i];
    }

    for (int i = -1; i <= c.getSize(); i++)
    {
        if (c.getTop() != '(')
            result += c.getTop();
        c.pop();
    }

    cout << result;
}

void calc()
{
    Stack<int> s;
    string str;
    str = "521--314++*";

    int num1, num2, res;

    for (int i = 0; i < str.size(); i++)
    {
        char p = str[i];
        if (isdigit(p))
        {
            s.push(p - '0');
        }
        else
        {
            s.pop(num1);
            s.pop(num2);

            switch (str[i])
            {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;

            default:
                break;
            }

            s.push(res);
        }
    }

    cout << s.getTop();
}

int main()
{
    calc();
    return 0;
}