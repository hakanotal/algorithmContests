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
    int n;
    cin >> n;
    string s;

    vector<vector<int>> indexes(4, vector<int>());

    cin >> s;
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'z':
            indexes[0].push_back(i);
            break;
        case 'e':
            indexes[1].push_back(i);
            break;
        case 'r':
            indexes[2].push_back(i);
            break;
        case 'o':
            indexes[3].push_back(i);
            break;
        default:
            break;
        }
    }

    int ans = 0;

    for (int z = 0; z < (int)indexes[0].size(); z++)
    {
        // indexes[0][z];
        for (int e = 0; e < (int)indexes[1].size(); e++)
        {
            if (indexes[0][z] < indexes[1][e])
            {
                for (int r = 0; r < (int)indexes[2].size(); r++)
                {
                    if (indexes[1][e] < indexes[2][r])
                    {
                        for (int o = 0; o < (int)indexes[3].size(); o++)
                        {
                            if (indexes[2][r] < indexes[3][o])
                            {
                                ans++;
                                ans %= M;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}