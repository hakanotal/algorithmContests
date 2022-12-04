// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        int min_C = 1000000, min_M = 1000000, min_Y = 1000000, min_K = 1000000;

        for (int j = 0; j < 3; j++)
        {
            int C, M, Y, K;
            cin >> C >> M >> Y >> K;
            min_C = min(min_C, C);
            min_M = min(min_M, M);
            min_Y = min(min_Y, Y);
            min_K = min(min_K, K);
        }

        int total = min_C + min_M + min_Y + min_K;
        int target = 1000000;

        if (total < target)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            int c, m, y, k;
            c = min(min_C, target);
            target -= c;
            m = min(min_M, target);
            target -= m;
            y = min(min_Y, target);
            target -= y;
            k = min(min_K, target);
            target -= k;
            //cout << min_C << " " << min_M << " " << min_Y << " " << min_K << " " << target << "\n";
            cout << c << " " << m << " " << y << " " << k << "\n";
        }
    }

    return 0;
}