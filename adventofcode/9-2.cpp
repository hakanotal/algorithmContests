// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

set<pair<int, int>> visited;
vector<pair<int, int>> K(10, make_pair(0, 0));

void update(int j)
{
    int diff_x = K[j].first - K[j + 1].first;
    int diff_y = K[j].second - K[j + 1].second;

    if (abs(diff_x) == 0 && abs(diff_y) == 2)
    {
        K[j + 1].second += (diff_y > 0 ? 1 : -1);
    }
    if (abs(diff_x) == 2 && abs(diff_y) == 0)
    {
        K[j + 1].first += (diff_x > 0 ? 1 : -1);
    }

    if (abs(diff_x) + abs(diff_y) >= 3)
    {
        K[j + 1].first += (diff_x > 0 ? 1 : -1);
        K[j + 1].second += (diff_y > 0 ? 1 : -1);
    }
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    string s;
    while (getline(cin, s))
    {
        char a;
        int b;
        stringstream ss(s);
        ss >> a >> b;

        for (int i = 0; i < b; i++)
        {
            if (a == 'U')
                K[0].second++;
            else if (a == 'D')
                K[0].second--;
            else if (a == 'R')
                K[0].first++;
            else if (a == 'L')
                K[0].first--;

            for (int j = 0; j < 9; j++)
                update(j);

            // cout << "H: " << K[0].first << "," << K[0].second << "\n";
            // cout << "T: " << K[1].first << "," << K[1].second << "\n\n";
            visited.insert(K[9]);
        }
    }

    cout << visited.size() << endl;

    return 0;
}