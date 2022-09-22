#include <bits/stdc++.h>

using namespace std;

void comb(int arr[], int data[], int start, int end, int index, int r)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        comb(arr, data, i + 1, end, index + 1, r);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 5;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i <= r; i++)
    {
        int data[i];
        comb(arr, data, 0, n - 1, 0, i);
    }
}
