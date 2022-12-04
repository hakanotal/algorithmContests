// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Algorithm
    vector<int> answer;
    int temp = 0;

    // Input
    string s;
    while (getline(cin, s))
    {
        if (!s.empty())
        {
            stringstream ss(s);
            int c;
            ss >> c;
            temp += c;
        }
        else
        {
            cout << "calories: " << temp << "\n";
            answer.push_back(temp);
            temp = 0;
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());

    //  Output
    cout << "max calories: " << answer[0] << "," << answer[1] << "," << answer[2] << "\n";
    cout << "sum top 3 calories: " << answer[0] + answer[1] + answer[2] << "\n";

    return 0;
}