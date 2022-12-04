// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

char choose(char a, char b)
{

    switch (a)
    {
    case 'A':
        switch (b)
        {
        case 'X':
            return 'Z';
        case 'Y':
            return 'X';
        case 'Z':
            return 'Y';
        default:
            break;
        }
        break;
    case 'B':
        switch (b)
        {
        case 'X':
            return 'X';
        case 'Y':
            return 'Y';
        case 'Z':
            return 'Z';
        default:
            break;
        }
        break;
    case 'C':
        switch (b)
        {
        case 'X':
            return 'Y';
        case 'Y':
            return 'Z';
        case 'Z':
            return 'X';
        default:
            break;
        }
        break;
    default:
        break;
    }
    
}

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
        char c = choose(a, b);
        int s = calc_score(a, c);
        cout << a << "-" << c << ": " << b << "..." << s << "\n";
        answer += s;
    }

    //  Output
    cout << answer << "\n";
    return 0;
}