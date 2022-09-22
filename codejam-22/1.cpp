// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

void cell(int a, int b, vector<vector<char>> &arr)
{
    int x = 2 * a + 1;
    int y = 2 * b + 1;
    arr[x - 1][y - 1] = '+';
    arr[x + 1][y - 1] = '+';
    arr[x - 1][y + 1] = '+';
    arr[x + 1][y + 1] = '+';
    arr[x][y - 1] = '|';
    arr[x][y + 1] = '|';
    arr[x - 1][y] = '-';
    arr[x + 1][y] = '-';
    arr[x][y] = '.';
}

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
        int R, C;
        cin >> R >> C;
        vector<vector<char>> arr(2 * R + 1, vector<char>(2 * C + 1));
        for (int y = 0; y < C; y++)
        {
            for (int x = 0; x < R; x++)
            {
                cell(x, y, arr);
            }
        }
        arr[0][0] = '.';
        arr[0][1] = '.';
        arr[1][0] = '.';

        cout << "Case #"<<i+1<<":\n";
        for (auto row : arr)
        {
            for (auto x : row)
            {
                cout << x;
            }
            cout << "\n";
        }
    }

    return 0;
}