#include <bits/stdc++.h>
using namespace std;

const int MAX_QUEUE = 5;

template <class T>
class Queue
{
private:
    int back;
    int front;
    int count;
    T arr[MAX_QUEUE];

public:
    Queue();
    void enQueue(T newItem);
    void delQueue(); // xoa dau
    // void delQueue(&);

    bool isEmpty() { return count == 0; };
    bool isFull() { return count == MAX_QUEUE; };
    T getFront() { return arr[front]; };
};

template <class T>
Queue<T>::Queue()
{
    count = 0;
    front = 0;
    back = MAX_QUEUE - 1;
}

template <class T>
void Queue<T>::enQueue(T newItem)
{
    if (isFull())
    {
        cout << "Array is full" << endl;
        return;
    }

    back = (back + 1) % MAX_QUEUE;
    arr[back] = newItem;
    count++;
}

template <class T>
void Queue<T>::delQueue()
{
    if (isEmpty())
    {
        cout << "Array is empty" << endl;
        return;
    }

    front = (back + 1) % MAX_QUEUE;
    count--;
}

int main()
{
    Queue<int> cQueue;
    cQueue.enQueue(1);
    cQueue.enQueue(2);
    cQueue.enQueue(3);
    cQueue.enQueue(4);
    cQueue.enQueue(5);

    int getFront = cQueue.getFront();
    cQueue.delQueue();
    cQueue.enQueue(6);
    cout << cQueue.getFront();

    return 0;
}