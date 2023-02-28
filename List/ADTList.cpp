#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

template <class T>
class ADTList
{
private:
    T arr[MAX];
    int length;

public:
    ADTList()
    {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;

        length = 5;
    }

    int arrSize()
    {
        return sizeof(arr) / sizeof(T);
    }

    bool isFull()
    {
        return length == MAX;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void pushFont(T number)
    {
        if (!isFull())
        {
            length++;
            for (int i = length; i >= 1; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = number;
        }
        else
        {
            cout << "Mang day" << endl;
        }
    }

    void pushBack(T number)
    {
        if (!isFull())
        {
            arr[length++] = number;
        }
        else
        {
            cout << "Mang day" << endl;
        }
    }

    void insert(int index, T number)
    {
        if (!isFull())
        {
            for (int i = length; i >= index; i--)
                arr[i] = arr[i - 1];

            arr[index - 1] = number;
            length++;
        }
        else
        {
            cout << "Mang day" << endl;
        }
    }

    void popFront()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < length - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            length--;
        }
        else
        {
            cout << "Mang rong" << endl;
        }
    }

    void popBack()
    {
        if (!isEmpty())
        {
            length--;
        }
        else
        {
            cout << "Mang rong" << endl;
        }
    }

    void remove(int index)
    {
        if (!isEmpty())
        {
            if (index >= 0 && index < length)
            {
                for (int i = index; i < length - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                length--;
            }
            else
            {
                cout << "Gia tri khong hop le." << endl;
            }
        }
        else
        {
            cout << "Mang rong" << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    ADTList<int> arr;
    arr.pushFont(0);
    arr.pushBack(6);
    arr.insert(5, 3);
    arr.popFront();
    arr.popBack();
    arr.remove(0);
    arr.print();
}