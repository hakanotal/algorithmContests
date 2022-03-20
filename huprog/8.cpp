// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
const int M = 1e9 + 7; // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int t, e;
    cin >> t >> e;
    vector<int> team(t);
    vector<int> eren(e);

    for (int i = 0; i < t; i++)
    {
        cin >> team[i];
    }
    for (int i = 0; i < e; i++)
    {
        cin >> eren[i];
    }
    sort(team.begin(), team.end(), greater<int>());
    sort(eren.begin(), eren.end());

    vector<int> answer(e, 0);

    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (eren[i] > team[j])
            {
                answer[i] = t - j;
                break;
            }
        }
    }

    for (int n : answer)
        cout << n << " ";

    return 0;
}