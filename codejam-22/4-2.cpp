// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>

using namespace std;

class Module
{
public:
    int fun;
    bool isActive = false;
    bool isStarter = true;
    vector<int> childs;
};
vector<Module> modules;

void reset()
{
    for (auto &m : modules)
        m.isActive = false;
}

int chain(int index, int fun)
{
    int newFun = max(fun, modules[index].fun);

    modules[index].isActive = true;

    int totalChilds = 0;
    int minChild = 0;
    for (int next = 0; next < (int)modules[index].childs.size(); next++)
    {
        if (!modules[modules[index].childs[next]].isActive)
        {
            int c = chain(modules[index].childs[next], newFun);
            totalChilds += c;
            minChild = min(minChild, c);
        }
        reset();
    }
    return max(newFun, minChild) + totalChilds;
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
            int f;
            cin >> f;
            m.fun = f;
            modules[j] = m;
        }
        vector<int> starters;
        for (int j = 0; j < N; j++)
        {
            int next;
            cin >> next;
            if (next == 0)
                starters.push_back(j);
            else
                modules[next - 1].childs.push_back(j);
        }
        int fun = 0;
        for (int start : starters)
        {
            cout << "starter: " << start << endl;
            fun += chain(start, 0);
        }

        cout << fun << endl;
    }

    return 0;
}