// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    string s;
    getline(cin, s);

    for(int i=3; i<s.length(); i++){
        set<char> uniques;
        for(int j=0; j<4; j++)
            uniques.insert(s[i-j]);
        //cout << s[i - 3] << s[i - 2] << s[i - 1] << s[i] << endl;
        if(uniques.size() == 4){
            cout << i + 1 <<endl;
            break;
        }
    }

    return 0;
}