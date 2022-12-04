// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int calc_score(char a, char b)
{
    int score = 0;

    if (b == 'X')
        score += 1;
    else if (b == 'Y')
        score += 2;
    else if (b == 'Z')
        score += 3;

    if ((a == 'A' && b == 'X') || (a == 'B' && b == 'Y') || (a == 'C' && b == 'Z'))
        score += 3;

    if ((a == 'A' && b == 'Y') || (a == 'B' && b == 'Z') || (a == 'C' && b == 'X'))
        score += 6;

    return score;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Algorithm
    int answer = -0;

    // Input
    string s;
    while (getline(cin, s))
    {

        stringstream ss(s);
        char a, b;
        ss >> a >> b;
        int s = calc_score(a, b);
        cout << a << " " << b << " " << s << "\n";
        answer += s;
    }

    //  Output
    cout << answer << "\n";
    return 0;
}