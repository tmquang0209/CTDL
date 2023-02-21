#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
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
    Stack()
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
void Stack<T>::push(T newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;

    newNode->next = (head == NULL) ? NULL : head;

    head = newNode;

    size++;
}

template <class T>
void Stack<T>::pop()
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
void Stack<T>::pop(T &stackTop)
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
T Stack<T>::getTop() const
{
    return head->item;
}