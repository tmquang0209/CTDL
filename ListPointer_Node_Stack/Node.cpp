#include <bits/stdc++.h>
using namespace std;

template <class T>
class List
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *head;
    int size;
    Node *find(int index)
    {
        Node *cur = head;
        for (int i = 1; i < index; i++)
            cur = cur->next;
        return cur;
    }

public:
    List()
    {
        size = 0;
        head = NULL;
    }
    void pushFront(T newItem);
    void popFront();
    void pushBack(T newItem);
    void popBack();
    void insert(int index, T newItem);
    void remove(int index);
    bool isEmpty();
    int getSize();
    T retrieve(int index)
    {
        Node *findNode = find(index - 1);
        return findNode->item;
    }
};

template <class T>
void List<T>::pushFront(T newItem)
{
    Node *newNode = new Node();
    newNode->item = newItem;

    Node *cur = head;
    head = newNode;
    newNode->next = cur;

    size++;
}

template <class T>
void List<T>::popFront()
{
    Node *popNode = head;
    head = head->next;
    delete popNode;
    size--;
}

template <class T>
void List<T>::pushBack(T newItem)
{
    Node *newNode = new Node();
    newNode->item = newItem;
    newNode->next = NULL;

    Node *prev = find(size);
    // newNode->next = p->next;
    prev->next = newNode;
    newNode->next = NULL;

    size++;
}

template <class T>
void List<T>::popBack()
{
    Node *node = find(size - 1);

    Node *del = node->next;
    node->next = NULL;

    delete del;
    size--;
}

template <class T>
void List<T>::insert(int index, T newItem)
{
    int newSize = size + 1;

    Node *newNode = new Node();
    newNode->item = newItem;
    if (index == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *previous = find(index - 1);
        newNode->next = previous->next;
        previous->next = newNode;
    }
    size = newSize;
}

template <class T>
void List<T>::remove(int index)
{
    Node *removeNode = find(index - 1);

    Node *del = removeNode->next;
    removeNode->next = del->next;
    del->next = NULL;
    delete del;
    size--;
}

template <class T>
bool List<T>::isEmpty()
{
    return head->next == NULL;
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

// template <class T>
// Node List<T>::retrieve(int index)
// {
//     Node *findNode = head;
//     for (int i = 1; i < index; i++)
//     {
//         findNode = findNode->next;
//     }
//     return findNode;
// }

int main()
{
    List<int> arr;
    arr.pushFront(23);
    // arr.pushBack(24);
    arr.insert(0, 30);
    // arr.pushBack(30);

    int value = arr.retrieve(3);
    cout << value << endl;

    arr.remove(1);
    value = arr.retrieve(1);
    cout << value;
}