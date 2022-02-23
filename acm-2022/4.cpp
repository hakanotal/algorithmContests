#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool calc(vector<int> &arr, int target, int last_pos)
{
    if (last_pos == 0)
        return false;

    int pos = last_pos;
    for (int it = last_pos - 1; it >= 0; it--)
    {
        if (arr[it] > target)
            pos--;
        else if (arr[it] == target)
        {
            // cout << arr[it] << " ";
            return true;
        }
        else
            break;
    }

    int last = arr[pos - 1];

    if (calc(arr, target - last, pos - 1))
    {
        // cout << last << " ";
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    // READ
    // ifstream f("out.txt");
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    // f.close();
    sort(arr.begin(), arr.end());

    int op = 0;
    int pos = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int it = pos; it < (int)arr.size(); it++)
        {
            if (arr[it] <= i)
                pos++;
            else
                break;
        }
        // cout << "\n" << i << " :";

        if (!calc(arr, i, pos))
        {
            op++;
            // cout << "added: " << i << endl;
            arr.emplace(arr.begin() + pos, i);
            pos++;
        }
    }

    cout << op << endl;

    return 0;
}