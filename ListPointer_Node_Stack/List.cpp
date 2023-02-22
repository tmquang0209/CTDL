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
        if (index > 0 && index <= size)
        {
            Node *cur = find(index);
            return cur->item;
        }
        else
        {
            cout << "Vi tri khong hop le" << endl;
            return -1;
        }
    }
};

template <class T>
void List<T>::pushFront(T newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;

    Node *cur = head;
    head = newNode;
    newNode->next = cur;

    size++;
}

template <class T>
void List<T>::popFront()
{
    Node *pop = head;
    head = head->next;
    delete pop;

    size--;
}

template <class T>
void List<T>::pushBack(T newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;
    
    Node *prev = find(size);

    prev->next = newNode;
    newNode->next = NULL;

    size++;
}

template <class T>
void List<T>::popBack()
{
    Node *prev = find(size - 1);

    Node *del = prev->next;
    prev->next = NULL;
    delete del;

    size--;
}

template <class T>
void List<T>::insert(int index, T newItem)
{
    int newSize = size + 1;
    Node *newNode = new Node;
    newNode->item = newItem;

    if (size == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *prev = find(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    size++;
}

template <class T>
void List<T>::remove(int index)
{
    if (index == 1)
    {
        Node *del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
    else
    {
        Node *prev = find(index - 1);
        Node *del = prev->next;
        prev->next = del->next;
        del->next = NULL;
        delete del;
    }
    size--;
}

template <class T>
bool List<T>::isEmpty()
{
    return size == 0;
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

int main()
{
    List<int> l;
    l.pushFront(23);
    l.insert(1, 30);
    l.pushBack(44);

    int value = l.retrieve(1);
    cout << value << endl;

    l.remove(1);
    value = l.retrieve(1);
    cout << value << endl;
    // l.remove(1);

    int size = l.getSize();
    cout << size << endl;
}