#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

template <class T>
class ArrayList
{
private:
    T arr[MAX];
    int size;

public:
    ArrayList();
    ArrayList(int sizeArr);
    ArrayList(T otherArr[], int sizeArr);
    void pushFront(T item);
    void pushBack(T item);
    void popFront();
    void popBack();
    void printList();
    void insert(int index, T newItem);
    void remove(int index);
    bool isEmpty();
    bool isFull();
    T retrieve(int index);
    int getSize();
};

template <class T>
ArrayList<T>::ArrayList()
{
    this->size = 0;
}

template <class T>
ArrayList<T>::ArrayList(int sizeArr)
{
    size = sizeArr;
}

template <class T>
ArrayList<T>::ArrayList(T otherArr[], int sizeArr)
{
    // cout << "123";
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = otherArr[i];
    }
    size = sizeArr;
}

template <class T>
void ArrayList<T>::pushFront(T item)
{
    if (isFull())
    {
        cout << "Mang day";
        return;
    }
    for (int i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = item;
    size++;
}

template <class T>
void ArrayList<T>::pushBack(T item)
{
    if (isFull())
    {
        cout << "Mang day";
        return;
    }
    arr[size] = item;
    size++;
}

template <class T>
void ArrayList<T>::popFront()
{
    if (isEmpty())
    {
        cout << "Mang rong";
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

template <class T>
void ArrayList<T>::popBack()
{

    if (isEmpty())
    {
        cout << "Mang rong";
        return;
    }
    size--;
}

template <class T>
void ArrayList<T>::printList()
{

    if (!isEmpty())
        for (int i = 0; i < size; i++)
        {
            cout << this->arr[i] << " ";
        }
}

template <class T>
void ArrayList<T>::insert(int index, T number)
{
    if (index < 0 || index > size)
    {
        cout << "Vi tri khong hop le";
        return;
    }
    else if (isFull())
    {
        cout << "Mang day";
        return;
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = number;
    size++;
}

template <class T>
void ArrayList<T>::remove(int index)
{
    if (isEmpty())
    {
        cout << "Mang rong";
        return;
    }
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

template <class T>
bool ArrayList<T>::isEmpty()
{
    return (size == 0);
}

template <class T>
bool ArrayList<T>::isFull()
{
    return (size == MAX);
}

template <class T>
T ArrayList<T>::retrieve(int index)
{
    return arr[index];
}

template <class T>
int ArrayList<T>::getSize()
{
    return size;
}

int main()
{
    ArrayList<int> arrList1;
    cout << arrList1.getSize() << endl;
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        arrList1.insert(i, rand() % 1000);
    }
    arrList1.printList();

    int max = arrList1.retrieve(0);
    int min = arrList1.retrieve(0);
    int sum = 0;

    for (int i = 0; i < arrList1.getSize(); i++)
    {
        if (arrList1.retrieve(i) > max)
        {
            max = arrList1.retrieve(i);
        }
        if (arrList1.retrieve(i) < min)
        {
            min = arrList1.retrieve(i);
        }
        sum += arrList1.retrieve(i);
    }
    cout << endl
         << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    cout << "AVG = " << (double)sum / arrList1.getSize() << endl;

    // tim kiem
    int n;
    cout << "Nhap n: ";
    cin >> n;

    bool flagSearch = true;

    for (int i = 0; i < arrList1.getSize(); i++)
    {
        if (arrList1.retrieve(i) == n)
        {
            cout << n << " duoc tim thay tai vi tri " << i << endl;
            flagSearch = false;
            break;
        }
    }

    if (flagSearch)
    {
        cout << "Khong tim thay gia tri " << n << endl;
    }
}