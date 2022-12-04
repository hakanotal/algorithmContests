// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int get_priority(char x){
    int a = int(x);
    if (a > 96 && a < 123)
        return a-96;    
    if (a > 64 && a < 91)
        return a-38;
    return 0;
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Algorithm
    int answer = 0;

    // Input
    string s;
    while (getline(cin, s))
    {
        int l = s.length() / 2;

        for(int i = 0; i < l; i++){
            for(int j = l; j < l*2; j++){
                if(s.at(i) == s.at(j)){
                    int p = get_priority(s.at(i));
                    cout << s.at(i) <<" - "<< p << "\n";
                    answer += p;
                    i = l;
                    break;
                }
            }
        }
        
    }

    //  Output
    cout << answer << "\n";
    return 0;
}