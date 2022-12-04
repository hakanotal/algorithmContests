// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<char> answer;
    vector<deque<char>> stacks(9, deque<char>());

    // Input
    string s;
    while (getline(cin, s))
    {
        for (int i = 1, j = 0; i < s.length(); i += 4, j++)
        {
            if (isalpha(s[i]))
                stacks[j].push_back(s[i]);
        }
        if (s.empty())
            break;
    }

    while (getline(cin, s))
    {
        stringstream ss(s);
        string _;
        int src, dst, val;
        ss >> _ >> val >> _ >> src >> _ >> dst;

        stack<char> temp;
        for (int i = 0; i < val; i++)
        {
            char c = stacks[src - 1].front();
            stacks[src - 1].pop_front();
            temp.push(c);
        }
        for (int i = 0; i < val; i++)
        {
            char c = temp.top();
            temp.pop();
            stacks[dst - 1].push_front(c);
        }
    }

    for (auto s : stacks)
    {
        answer.push_back(s.front());
        for (auto c : s)
            cout << c;
        cout << endl;
    }
    cout << endl;

    for (auto c : answer)
        cout << c;

    return 0;
}