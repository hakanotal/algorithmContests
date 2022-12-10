// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int X = 1, cycle_count = 1;
int H = 0, V = 0;
vector<vector<char>> CRT(6, vector<char>(40, '.'));

void print()
{
    for (auto row : CRT)
    {
        for (auto p : row)
        {
            cout << p;
        }
        cout << "\n";
    }
}

void new_cycle()
{

    if (H == X - 1 || H == X || H == X + 1)
        CRT[V][H] = '#';

    if (cycle_count % 40 == 0)
    {
        V++;
        H = 0;
    }
    else
    {
        H++;
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

    print();

    return 0;
}