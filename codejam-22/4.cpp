// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>

using namespace std;

class Module
{
public:
    int fun;
    bool isActive = false;
    bool isStarter = true;
    int nextIndex;

    void readFun()
    {
        cin >> fun;
    }
    void readNext()
    {
        cin >> nextIndex;
    }
};
vector<Module> modules;

int chain(int index, int fun)
{
    int newFun = max(fun, modules[index].fun);

    modules[index].isActive = true;

    if (modules[modules[index].nextIndex - 1].isActive)
        return newFun;
    else
        return chain(modules[index].nextIndex - 1, newFun);
}

void reset()
{
    for (auto &m : modules)
        m.isActive = false;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";

        int N;
        cin >> N;
        modules.resize(N);
        for (int j = 0; j < N; j++)
        {
            Module m;
            m.readFun();
            modules[j] = m;
        }
        for (int j = 0; j < N; j++)
        {
            modules[j].readNext();
            if (modules[j].nextIndex > 0)
                modules[modules[j].nextIndex - 1].isStarter = false;
        }

        vector<int> starters;
        for (int j = 0; j < N; j++)
        {
            if (modules[j].isStarter)
                starters.push_back(j);
        }

        // Output
        int answer = -1;
        do
        {
            int totalFun = 0;
            for (int start : starters)
            {
                totalFun += chain(start, 0);
            }
            answer = max(answer, totalFun);
            cout << "Test: " << totalFun << endl;
            reset();
        } while (next_permutation(starters.begin(), starters.end()));

        cout << answer << endl;
    }
    return 0;
}