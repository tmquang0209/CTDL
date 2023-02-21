#include <bits/stdc++.h>
#include "Queue.cpp"
#include "Stack.cpp"
using namespace std;

static Stack<char> stackChar;
static Queue<char> queueChar;

void addStackAll(string str);
void enQueueAll(string str);
bool palindrome();

int main()
{
    string str = "A b c c b A";
    addStackAll(str);
    enQueueAll(str);

    if (palindrome())
        cout << "true";
    else
        cout << "false";
    return 0;
}

void addStackAll(string str)
{
    for (int i = 0; i < str.size(); i++)
        stackChar.push(str[i]);
}

void enQueueAll(string str)
{
    for (int i = 0; i < str.size(); i++)
        queueChar.addQueue(str[i]);
}

bool palindrome()
{
    while (!stackChar.isEmpty() || !queueChar.isEmpty())
    {
        if (stackChar.getTop() != queueChar.getFront())
            return false;
        else
        {
            stackChar.pop();
            queueChar.delQueue();
        }
    }
    return true;
}