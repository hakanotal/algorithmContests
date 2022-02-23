#include <iostream>
#include <vector>

using namespace std;

bool calc(vector<int> arr, int target)
{
    if (arr.size() == 0)
        return false;

    // cout << "\nt: " << target << " - ";
    int sum = 0;
    vector<int> subarr;
    for (auto it : arr)
    {
        // cout << it << " ";
        sum += it;
        if (it == target)
            return true;
        else if (it < target)
            subarr.push_back(it);
    }
    if (sum < target)
        return false;

    int last = subarr.back();
    subarr.pop_back();

    if (calc(subarr, target - last))
        return true;
    else if (calc(subarr, target))
        return true;
    else
        return false;
}

int main()
{
    // READ
    int n, k;
    cin >> n >> k;

    vector<int> memo(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        memo[x] = 1;
    }

    int op = 0;
    vector<int> arr;
    for (int i = 1; i <= k; i++)
    {
        if (memo[i] == 1)
            arr.push_back(i);
        else
        {
            if (!calc(arr, i))
            {
                arr.push_back(i);
                op++;
            }
        }
    }

    cout << op;

    return 0;
}