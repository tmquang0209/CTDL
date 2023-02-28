#include <bits/stdc++.h>
using namespace std;

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int *quickSort(int *arr, int left, int right)
{

    int x, i, j;
    x = arr[(left + right) / 2];
    i = left;
    j = right;
    do
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
    } while (i < j);

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
    return arr;
}

int main()
{
    int n = 10;
    int *arr = new int[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    int *qs = quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << qs[i] << " ";
    }
}