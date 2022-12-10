// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

set<pair<int, int>> visited;
pair<int, int> H(0, 0);
pair<int, int> T(0, 0);

void update(char dir)
{
    if (dir == 'U')
        H.second++;
    else if (dir == 'D')
        H.second--;
    else if (dir == 'R')
        H.first++;
    else if (dir == 'L')
        H.first--;

    int diff_x = H.first - T.first;
    int diff_y = H.second - T.second;

    if (abs(diff_x) == 0 && abs(diff_y) == 2)
    {
        T.second += (diff_y > 0 ? 1 : -1);
    }
    if (abs(diff_x) == 2 && abs(diff_y) == 0)
    {
        T.first += (diff_x > 0 ? 1 : -1);
    }

    if (abs(diff_x) + abs(diff_y) == 3)
    {
        T.first += (diff_x > 0 ? 1 : -1);
        T.second += (diff_y > 0 ? 1 : -1);
    }

    visited.insert(T);
    // cout << "H: " << H.first << "," << H.second << "\n";
    // cout << "T: " << T.first << "," << T.second << "\n\n";
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
            update(a);
    }

    cout << visited.size() << endl;

    return 0;
}