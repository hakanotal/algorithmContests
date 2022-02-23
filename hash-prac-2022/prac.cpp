#include <bits/stdc++.h>

using namespace std;

static map<string, int> ingreds;
int most_liked = 0;
int most_disliked = 0;

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

            most_liked = max(most_liked, pos->second);
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

            most_disliked = min(most_disliked, pos->second);
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
    vector<string> table;
    vector<pair<string, int>> others;

    for (auto &it : ingreds)
    {
        // double chance = (it.second + most_disliked) * (100 / (most_liked - most_disliked)); // map between 0-100
        // if (rand() * 100 < chance)
        if (it.second > 1)
            table.push_back(it.first);
        else if (it.second > -2)
        {
            others.push_back(it);
        }
    }

    int count = calcCustomer(table);
    cout << "table size: " << table.size() << " count: " << count << "\n";

    for (auto &it : others)
    {

        cout << "trying: " << it.second << "\n";

        vector<string> t = table;
        t.push_back(it.first);
        int c = calcCustomer(t);

        if (c > count)
        {
            count = c;
            table.push_back(it.first);
            cout << "table size: " << table.size() << " count: " << count << "\n";
        }
    }

    cout << "best : " << count << "/" << (int)customers.size() << "\n";

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

    cout << "most liked : " << most_liked << "\n";
    cout << "most disliked : " << most_disliked << "\n";

    return 0;
}