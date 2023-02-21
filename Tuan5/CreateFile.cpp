#include <bits/stdc++.h>
using namespace std;

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

void readFile(int size)
{
    int arr[size];

    fstream file;
    file.open("randomInt.txt", ios::in);
    string str;

    for (int i = 0; i < size; i++)
        file >> arr[i];

    cout << "Print array" << endl;
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0)
            cout << endl;
        cout << arr[i] << "\t";
    }
}

int main()
{
    int size = 1000, limit = 10000;
    writeFile(size, limit);
    readFile(size);
}