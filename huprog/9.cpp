// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
const int M = 1e9 + 7; // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int t;
    cin >> t;
    int max_test = -1;
    vector<int> tests(t);
    for (int i = 0; i < t; i++)
    {
        cin >> tests[i];
        max_test = max(max_test, tests[i]);
    }

    vector<double> prob(max_test);
    // --
    prob[0] = 0.5;
    prob[1] = 0.75;
    for (int i = 2; i < max_test; i++)
        prob[i] = (prob[i - 1] + prob[i - 2]) * 0.5;

    cout << fixed;
    cout << setprecision(6);
    for (int n : tests)
        cout << prob[n - 1] << endl;

    return 0;
}