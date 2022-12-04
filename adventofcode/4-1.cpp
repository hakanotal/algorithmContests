// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Algorithm
    int answer = 0;

    // Input
    string s;
    while (getline(cin, s))
    {
        char _;
        int a, b, c, d;
        stringstream ss(s);
        ss >> a >> _ >> b >> _ >> c >> _ >> d;

        if (a >= c && b <= d || c >= a && d <= b)
        {
            cout << a << " - " << b << " , ";
            cout << c << " - " << d << "\n";
            answer++;
        }
    }

    //  Output
    cout << answer << "\n";
    return 0;
}