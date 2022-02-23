#include <bits/stdc++.h>

using namespace std;

map<string, int> ingreds;

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

            auto pos = ingreds.find(s);
            if (pos == ingreds.end())
                ingreds.insert(pair<string, int>(s, 1));
            else
                pos->second++;
            likes.push_back(s);
        }

        file >> D;
        for (int i = 0; i < D; i++)
        {
            string s;
            file >> s;

            auto pos = ingreds.find(s);
            if (pos == ingreds.end())
                ingreds.insert(pair<string, int>(s, -1));
            else
                pos->second--;
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

int calcCustomer(vector<string> &ingredList)
{
    int count = 0;
    for (auto c : customers)
    {
        bool ok = true;
        for (auto l : c.likes)
            if (find(ingredList.begin(), ingredList.end(), l) == ingredList.end())
                ok = false;

        for (auto d : c.dislikes)
            if (find(ingredList.begin(), ingredList.end(), d) != ingredList.end())
                ok = false;

        if (ok)
            count++;
    }
    return count;
}

vector<string> answer()
{
    vector<string> best_table;
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
        best_table.push_back(it);
        ingreds.erase(it);
    }
    for (auto it : full_disliked)
        ingreds.erase(it);

    int count = calcCustomer(best_table);
    cout << "count: " << count << " ingredsize: " << ingreds.size() << "/" << ingsize << "\n";

    return best_table;
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