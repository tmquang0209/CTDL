#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *head;
    Node *tail;

public:
    Queue() { head = tail = NULL; }
    void addQueue(T newItem);
    void delQueue(); // xoa dau

    bool isEmpty() { return head == NULL; };
    T getFront() { return head->item; };
    T getBack() { return tail->item; };
};

template <class T>
void Queue<T>::addQueue(T newItem)
{
    Node *newNode = new Node();
    newNode->item = newItem;
    newNode->next = NULL;

    if (tail == NULL)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

template <class T>
void Queue<T>::delQueue()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *del = head;
    if (head->next == NULL)
        head = tail = NULL;
    else
        head = head->next;

    del->next = NULL;
    delete del;
}

void Palindrome()
{
    Queue<char> cQueue;
    string str = "A b c c b A";

    // insert to queue
    for (int i = 0; i < str.size(); i++)
        cQueue.addQueue(str[i]);
}