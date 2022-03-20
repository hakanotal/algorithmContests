// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
const int M = 1e9 + 7; // for modulo

using namespace std;

vector<bool> primes;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool sortLogic(const pair<string, int> &s1, const pair<string, int> &s2)
{
    string a = s1.first;
    string b = s2.first;
    int m = (int) a.length();

    for (int i = 0; i < m; i++)
    {
        if (a[i] != b[i])
        {
            if (primes[i])
            {
                return a[i] > b[i];
            }
            else
            {
                return a[i] < b[i];
            }
        }
    }

    return true;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> strings;

    if (n > 0)
    {
        if (m > 0)
        {
            for (int i = 0; i < n; i++)
            {
                string s;
                cin >> s;
                strings.push_back(make_pair(s, i + 1));
                primes.push_back(isPrime(i));
            }

            sort(strings.begin(), strings.end(), sortLogic);

            for (auto s : strings)
                cout << s.first << endl;
            for (auto s : strings)
                cout << s.second << " ";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                string s;
                getline(cin, s);
            }

            for (int i = 0; i < n; i++)
            {
                cout << endl;
            }
            for (int j = 0; j < n; j++)
            {
                cout << j + 1 << " ";
            }
        }
    }

    return 0;
}