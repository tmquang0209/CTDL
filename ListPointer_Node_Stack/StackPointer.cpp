#include <bits/stdc++.h>
using namespace std;

template <class T>
class StackPointer
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    int size;
    Node *head;

public:
    StackPointer()
    {
        size = 0;
        head = NULL;
    }

    void push(T newItem);
    void pop();
    void pop(T &stackTop);
    bool isEmpty() const
    {
        return (size == 0);
    }
    T getTop() const;
    int getSize() const
    {
        return this->size;
    }
};

template <class T>
void StackPointer<T>::push(T newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;

    newNode->next = (head == NULL) ? NULL : head;

    head = newNode;

    size++;
}

template <class T>
void StackPointer<T>::pop()
{
    if (!isEmpty())
    {
        Node *del = head;
        head = head->next;

        del->next = NULL;
        delete del;

        size--;
    }
    else
    {
        cout << "pop, mang rong" << endl;
    }
}

template <class T>
void StackPointer<T>::pop(T &stackTop)
{
    if (!isEmpty())
    {
        stackTop = head->item;
        pop();
    }
    else
    {
        cout << "popT, mang rong" << endl;
    }
}

template <class T>
T StackPointer<T>::getTop() const
{
    return head->item;
}

template <class T>
void balance(string text, StackPointer<T> &stack)
{
    int count = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '(')
        {
            stack.push('(');
        }
        else if (text[i] == ')')
        {
            if (stack.isEmpty())
                count++;
            stack.pop();
        }
    }

    if (stack.getSize() - count == 0)
        cout << "Can bang ngoac." << endl;
    else
        cout << "Khong can bang ngoac." << endl;
}

int main()
{
    StackPointer<char> stackText;
    balance<char>(")))(((", stackText);
    // StackPointer<int> sp;
    // sp.push(1);
    // sp.push(2);
    // sp.push(3);
    // sp.push(4);

    // sp.pop();

    // int res;
    // sp.pop(res);

    // cout << "res = " << res << endl;
    // cout << "top = " << sp.getTop() << endl;
}