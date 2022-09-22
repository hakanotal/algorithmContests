#include <iostream>
#include <vector>

using namespace std;

unsigned int cost = 0;
const unsigned int M = 1000000007;

void bubbleSort(vector<int> &arr)
{
    int n = (int)arr.size();
    int index = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int real = arr[i] - 1 + index;
        if (real > i)
        {
            for (int j = i + 1; j <= real; j++)
            {
                if (arr[i] > arr[j])
                {
                    index++;
                    cost += arr[i] - arr[j];
                    // cout << cost << " : " << arr[i] << " - " << arr[j] << endl;
                    cost = cost % M;
                }
            }
        }
    }
}

int main()
{
    vector<int> arr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    bubbleSort(arr);

    cout << cost << endl;

    return 0;
}