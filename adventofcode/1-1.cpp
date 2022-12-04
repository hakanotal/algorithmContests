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
    int answer = -1;
    int temp = 0;

    // Input
    string s;
    while (getline(cin, s))
    {
        if (!s.empty())
        {
            stringstream ss(s);
            int c;
            ss >> c;
            temp += c;
        }
        else {
            cout << "calories: " << temp << "\n";
            answer = max(temp, answer);
            temp = 0;
        }
    }

    //  Output
    cout << "max calories: " << answer << "\n";

    return 0;
}