#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

class Object
{
public:
    int A;

    void read()
    {
        cin >> A;
        for (int i = 0; i < A; i++)
        {
            string s;
            cin >> s;
        }
    }
};

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        Object o;
        o.read();
    }

    // Algorithm
    vector<int> answer;

    //  Output
    cout << C << "\n";
    for (auto &a : answer)
    {
        cout << a;
    }

    return 0;
}