#include <bits/stdc++.h>

using namespace std;

map<string, pair<int, int>> ingreds;
class Customer
{
public:
    int L, D, id;
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

int calcCustomer(vector<string> &ingredList)
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

void answer()
{
    int n = customers.size();
    cout << "n: " << n << "\n";

    vector<vector<int>> adj(n, vector<int>(n, 0));

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool case1 = true;
            for (auto l : customers[i].likes)
            {
                for (auto d : customers[j].dislikes)
                {
                    if (l == d)
                    {
                        // cout << "intersection: " << i << " " << j << "\n";
                        case1 = false;
                    }
                }
            }

            bool case2 = true;
            for (auto l : customers[j].likes)
            {
                for (auto d : customers[i].dislikes)
                {
                    if (l == d)
                    {
                        // cout << "intersection: " << i << " " << j << "\n";
                        case2 = false;
                    }
                }
            }

            if (case1 && case2)
            {
                // cout << i << "-" << j << "\n";
                adj[i][j] = 1;
                adj[j][i] = 1;
                count++;
            }
        }
        // groups.push_back(g);
    }
    cout << count << "\n";

    ofstream f("adj2.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            f << adj[i][j] << " ";
        f << "\n";
    }
    f.close();
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);

    ifstream file("c.txt");
    int C;
    file >> C;
    for (int i = 0; i < C; i++)
    {
        Customer c1;
        c1.id = i;
        c1.read(file);
        customers.push_back(c1);
    }
    file.close();

    answer();

    return 0;
}