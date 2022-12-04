// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int get_priority(char x)
{
    int a = int(x);
    if (a > 96 && a < 123)
        return a - 96;
    if (a > 64 && a < 91)
        return a - 38;
    return 0;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Algorithm
    int answer = 0;

    // Input
    vector<string> input;
    string s;
    while (getline(cin, s))
    {
        input.push_back(s);
    }

    for (int ss = 2; ss < input.size(); ss += 3)
    {

        string ss1 = input[ss - 2];
        string ss2 = input[ss - 1];
        string ss3 = input[ss];

        bool found = false;
        for (char s1 : ss1)
        {
            for (char s2 : ss2)
            {
                for (char s3 : ss3)
                {
                    if (s1 == s2 && s2 == s3)
                    {
                        int p = get_priority(s1);
                        cout << s1 << " - " << p << "\n";
                        answer += p;
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
    }

    //  Output
    cout << answer << "\n";
    return 0;
}