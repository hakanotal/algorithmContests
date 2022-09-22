#include <bits/stdc++.h>

using namespace std;

static map<string, pair<int, int>> ingreds;

class Customer
{
public:
    int L, D;
    vector<string> likes;
    vector<string> dislikes;

    void read(ifstream &file)
    {
        file >> L;
        for (int i = 0; i < L; i++)
        {
            string s;
            file >> s;
            pair<int, int> p = make_pair(1, 0);

            auto pos = ingreds.find(s);
            if (pos == ingreds.end())
                ingreds.insert(make_pair(s, p));
            else
                pos->second.first++;
            likes.push_back(s);
        }

        file >> D;
        for (int i = 0; i < D; i++)
        {
            string s;
            file >> s;
            pair<int, int> p = make_pair(0, 1);

            auto pos = ingreds.find(s);
            if (pos == ingreds.end())
                ingreds.insert(make_pair(s, p));
            else
                pos->second.second++;
            dislikes.push_back(s);
        }
    }

    void print()
    {
        cout << "\nL: ";
        for (int i = 0; i < L; i++)
            cout << likes[i] << " ";
        cout << "\nD: ";
        for (int i = 0; i < D; i++)
            cout << dislikes[i] << " ";
    }
};

vector<Customer> customers;

int calcCustomer(vector<string> ingredList)
{
    int count = 0;
    for (auto c : customers)
    {
        bool ok = true;
        for (auto l : c.likes)
            if (find(ingredList.begin(), ingredList.end(), l) == ingredList.end())
            {
                ok = false;
                break;
            }
        if (ok)
            for (auto d : c.dislikes)
                if (find(ingredList.begin(), ingredList.end(), d) != ingredList.end())
                {
                    ok = false;
                    break;
                }

        if (ok)
            count++;
    }
    return count;
}

int recur(vector<string> table, int index, vector<string> remains, int n)
{
    if (index == n)
    {
        int c = calcCustomer(table);
        cout << "c: " << c << "\n";
        return c;
    }

    vector<string> t = table;
    t.push_back(remains[index]);
    int a = recur(t, index + 1, remains, n);

    t.pop_back();
    int b = recur(t, index + 1, remains, n);

    return max(a, b);
}

vector<string> answer()
{
    vector<string> table;
    int ingsize = ingreds.size();

    set<string> full_liked;
    set<string> full_disliked;

    for (auto c : customers)
        for (auto l : c.likes)
            full_liked.insert(l);

    for (auto c : customers)
        for (auto d : c.dislikes)
        {
            full_liked.erase(d);
            full_disliked.insert(d);
        }

    for (auto c : customers)
        for (auto l : c.likes)
            full_disliked.erase(l);

    for (auto it : full_liked)
    {
        table.push_back(it);
        ingreds.erase(it);
    }
    for (auto it : full_disliked)
        ingreds.erase(it);

    int count = calcCustomer(table);
    cout << "count: " << count << " ingredsize: " << ingsize << "->" << ingreds.size() << "\n";

    vector<string> remains;

    for (auto &i : ingreds)
    {
        if (i.second.first - i.second.second >= 0)
            table.push_back(i.first);
        else if (i.second.first - i.second.second == -1)
            remains.push_back(i.first);
    }

    count = calcCustomer(table);
    cout << "count: " << count << "\n";

    int n = remains.size();
    cout << "remains: " << n << "\n";

    int c = recur(table, 0, remains, n);
    cout << "best : " << c << "\n";

    return table;
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);

    ifstream file("e.txt");
    int C;
    file >> C;
    for (int i = 0; i < C; i++)
    {
        Customer c1;
        c1.read(file);
        customers.push_back(c1);
    }
    file.close();

    vector<string> best = answer();

    ofstream out("e.out.txt");
    int I = best.size();
    out << I;
    for (auto it : best)
        out << " " << it;
    out.close();

    return 0;
}