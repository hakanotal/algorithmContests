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
    int x;
    cin >> x;
    int total = 0;
    int max_candy_child = -1;
    for (int i = 0; i < x; i++)
    {
        int c;
        cin >> c;
        total += c;
        max_candy_child = max(max_candy_child, c);
    }

    int n;
    cin >> n;
    total += n;

    if (total % x != 0)
        cout << 0;
    else
    {
        int pay = total / x;
        if (pay < max_candy_child)
            cout << 0;
        else
            cout << 1;
    }

    return 0;
}