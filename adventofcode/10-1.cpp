// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int X = 1, cycle_count = 1;
int sum = 0;

void new_cycle()
{
    if ((cycle_count - 20) % 40 == 0 && cycle_count < 260)
    {
        sum += cycle_count * X;
        cout << cycle_count << " - " << X << " : " << cycle_count * X << endl;
    }
    cycle_count++;
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
        stringstream ss(s);
        string op;
        ss >> op;

        if (op.compare("noop") == 0)
        {
            new_cycle();
        }
        else
        {
            int val;
            ss >> val;
            new_cycle();
            new_cycle();
            X += val;
        }
    }
    cout << sum << endl;

    return 0;
}