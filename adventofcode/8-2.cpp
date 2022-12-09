// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

int calcScore(int pos_x, int pos_y, int size, vector<vector<int>> &H){
    int up = 0, down = 0, left = 0, right = 0;

    // Check up
    for (int i = pos_y - 1; i >= 0; i--)
    {
        up++;
        if (H[i][pos_x] >= H[pos_y][pos_x])
            break;
    }

    // Check down
    for (int i = pos_y + 1; i <= size; i++)
    {
        down++;
        if (H[i][pos_x] >= H[pos_y][pos_x])
            break;
    }

    // Check left
    for (int i = pos_x - 1; i >= 0; i--)
    {
        left++;
        if (H[pos_y][i] >= H[pos_y][pos_x])
            break;
    }

    // Check right
    for (int i = pos_x + 1; i <= size; i++)
    {
        right++;
        if (H[pos_y][i] >= H[pos_y][pos_x])
            break;
    }

    return up * down * left * right;
}

    int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> heights;
    int maxScore = 0;

    // Input
    string s;
    int size = 0;
    int i = 0;
    while (getline(cin, s))
    {
        heights.push_back(vector<int>());

        size = s.size() - 1;
        stringstream ss(s);
        char h;
        while (ss >> h && h != ' ')
        {
            heights[i].push_back(atoi(&h));
        }
        i++;
    }

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            maxScore = max(maxScore, calcScore(j, i, size, heights));
        }
    }
    
    cout << maxScore << endl;

    return 0;
}