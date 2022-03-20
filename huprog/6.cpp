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
    int n, x, y, dir;
    cin >> n;
    cin >> x >> y;
    cin >> dir;

    int start, end, player;
    if (dir == 1)
    {
        start = y;
        end = y;
        player = n - x - 1;
    }
    else if (dir == 3)
    {
        start = y;
        end = y;
        player = x;
    }
    else if (dir == 0)
    {
        start = x;
        end = x;
        player = n - y - 1;
    }
    else if (dir == 2)
    {
        start = x;
        end = x;
        player = y;
    }

    int answer = 0;
    for (int step = player; step < n; step++)
    {
        answer += end - start + 1;
        start = max(0, start - 1);
        end = min(n - 1, end + 1);
    }
    cout << answer;

    return 0;
}