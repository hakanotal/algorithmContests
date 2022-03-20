// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
const int M = 1e9 + 7; // for modulo

using namespace std;

bool isPalindrome(const string &s)
{
    int n = (int)s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

bool isK(const string &s, int n, int k)
{
    for (int i = 0; i < n - k - 1; i++)
    {
        if (s[i] != s[i + k])
            return false;
    }
    return true;
}

int solve(string s, int n, int k)
{
    int swap=0;
    if(n-k < (int)s.size()/2){
        for(int i = 0;i<n-k-1;i++){
            if(!isK(s,n,k)){
                s[i] = s[i+k];
                swap++;
            }
        }
        for(int i=0;i<s.size();i++){
            for(int j=s.size(); j>0;j--){
                if(!isPalindrome(s)){
                    s[i] = s[j];
                    swap++;
                }
            }
        }
    }
    return swap;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int q;
    cin >> q;
    vector<int> answers(q);
    for (int test = 0; test < q; test++)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        answers[test] = solve(s, n, k);
    }

    for (auto a : answers)
        cout << a << endl;

    return 0;
}