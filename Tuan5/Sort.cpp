#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void writeFile(int size, int limit)
{
    fstream file;
    file.open("randomInt.txt", ios::out);

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        file << rand() % limit << endl;
    }

    file.close();
}

int *readFile(int size)
{
    int *arr = new int[size];

    fstream file;
    file.open("randomInt.txt", ios::in);
    string str;

    for (int i = 0; i < size; i++)
        file >> arr[i];

    return arr;
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int *selectionSort(int *arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
    return arr;
}

int *quickSort1(int *arr, int low, int high)
{
    int i, j, x;
    x = arr[(high + low) / 2];
    i = low;
    j = high;

    while (i < j)
    {
        while (arr[i] < x)
            i++;

        while (arr[j] > x)
            j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quickSort1(arr, low, j);

    if (i < high)
        quickSort1(arr, i, high);

    return arr;
}

void print(int *arr, int size)
{
    cout << "Print array" << endl;
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0)
            cout << endl;
        cout << arr[i] << "\t";
    }
}

auto getClock()
{
    return high_resolution_clock::now();
}

int main()
{

    int size = 1000, limit = 10000;

    // writeFile(size, limit);

    // int *arr = readFile(size);
    // auto start = high_resolution_clock::now();
    // ios_base::sync_with_stdio(false);
    // int *slcSort = selectionSort(arr, size);
    // auto stop = high_resolution_clock::now();
    // print(slcSort, size);

    int *arr1 = readFile(size);
    auto start = getClock();
    int *qSort = quickSort1(arr1, 0, size - 1);
    auto stop = getClock();

    print(qSort, size);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
}