#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

class Object
{
public:
    int A;

    void read(ifstream &file)
    {
        file >> A;
        for (int i = 0; i < A; i++)
        {
            string s;
            file >> s;
        }
    }
};

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    ifstream file("e.txt");
    int C;
    file >> C;
    for (int i = 0; i < C; i++)
    {
        Object o;
        o.read(file);
    }
    file.close();

    // Algorithm
    vector<int> answer;

    //  Output
    ofstream file2("e.out.txt");
    for (auto &a : answer)
    {
        file2 << a;
    }
    file2.close();

    return 0;
}