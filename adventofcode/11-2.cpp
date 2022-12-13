// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

class Monkey;

vector<Monkey *> monkeys;
long ekok = 1;

class Monkey
{
public:
    vector<long> items;
    char opType;
    int opValue = -1;
    int testValue, nextTrue, nextFalse;
    int inspected = 0;

    void read()
    {
        string s, op, test;
        char _;
        int val;

        getline(cin, s);

        getline(cin, s);
        size_t found = s.find(":");
        stringstream ss1(s.substr(found + 1));
        while (ss1 >> val >> _)
            items.push_back(val);
        items.push_back(val);

        getline(cin, s);
        found = s.find("old");
        stringstream ss2(s.substr(found + 4));
        ss2 >> opType >> op;
        if (op != "old")
            opValue = stoi(op);

        getline(cin, s);
        found = s.find("by");
        stringstream ss3(s.substr(found + 3));
        ss3 >> testValue;

        getline(cin, s);
        found = s.find("monkey");
        stringstream ss4(s.substr(found + 7));
        ss4 >> nextTrue;

        getline(cin, s);
        found = s.find("monkey");
        stringstream ss5(s.substr(found + 7));
        ss5 >> nextFalse;

        getline(cin, s);
    }

    void print()
    {
        cout << "Items: ";
        for (int i = 0; i < items.size(); i++)
            cout << items[i] << " ";
        cout << endl;
        cout << "Op: " << opType << " " << opValue << endl;
        cout << "Test: " << testValue << endl;
        cout << "Next: " << nextTrue << " " << nextFalse << endl;
        cout << "Inspected: " << inspected << endl;
    }

    void turn(int turn)
    {
        if (items.size() > 0)
        {
            for (int i = 0; i < items.size(); i++)
            {
                inspected++;
                long W = items[i];

                if (opType == '*')
                    W *= (opValue == -1 ? W : opValue);
                else if (opType == '+')
                    W += (opValue == -1 ? W : opValue);
                else if (opType == '-')
                    W -= (opValue == -1 ? W : opValue);
                else if (opType == '/')
                    W /= (opValue == -1 ? W : opValue);

                W = W % ekok;

                if (W % testValue == 0)
                    monkeys[nextTrue]->items.push_back(W);
                else
                    monkeys[nextFalse]->items.push_back(W);
            }
            items.clear();
        }
    }
};

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    string s;
    for (int i = 0; i < 8; i++)
    {
        Monkey *m = new Monkey();
        m->read();
        monkeys.push_back(m);
        ekok *= m->testValue;
    }

    for (int i = 0; i < monkeys.size(); i++)
    {
        cout << "\nMonkey " << i << endl;
        monkeys[i]->print();
    }

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < monkeys.size(); j++)
        {
            monkeys[j]->turn(i);
        }
        if (i == 0 || i==20)
        {
            cout << "\nTurn: " << i << endl;
            for (int j = 0; j < monkeys.size(); j++)
            {
                cout << "\nMonkey " << j << endl;
                monkeys[j]->print();
            }
        }
    }

    cout << "\nTurn: " << 10000 << endl;
    vector<long> maxs;
    for (int j = 0; j < monkeys.size(); j++)
    {
        cout << "\nMonkey " << j << endl;
        monkeys[j]->print();
        maxs.push_back(monkeys[j]->inspected);
    }

    sort(maxs.begin(), maxs.end(), greater<long>());
    cout << "\nMax: " << maxs[0] << " * " << maxs[1] << " = " << maxs[0] * maxs[1] << endl;

    return 0;
}