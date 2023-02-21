#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class SinhVien
{
private:
    string code;
    double avg;

public:
    SinhVien()
    {
        code = "0";
        avg = 0;
    }

    SinhVien(string code, double avg)
    {
        this->code = code;
        this->avg = avg;
    }

    friend ostream &operator<<(ostream &os, const SinhVien &sv)
    {
        os << "Student id: " << sv.code
           << "\tAvg: " << sv.avg << endl;

        return os;
    }

    friend istream &operator>>(istream &is, SinhVien &sv)
    {
        cout << "Ma SV: ";
        is >> sv.code;

        cout << "Diem TB: ";
        is >> sv.avg;

        return is;
    }
};

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

int main()
{
    SinhVien sv1("A12345", 5);
    SinhVien sv2;
    cin >> sv2;

    Stack<SinhVien> sv;
    sv.push(sv1);
    sv.push(sv2);

    cout << sv.getTop();
    sv.pop();

    cout << sv.getTop();
    // Stack<int> s1;
    // s1.push(10);
    // s1.push(20);
    // cout << s1.getTop() << endl;

    // s1.pop();
    // s1.pop();
    // s1.pop();
    // int res;
    // s1.pop(res);
    // cout << res << endl;
}