// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

bool isVisible(int pos_x, int pos_y, int size, vector<vector<int>> &H){
    bool up = true, down = true, left = true, right = true;

    // Check up
    for (int i = pos_y - 1; i >= 0; i--)
    {
        if (H[i][pos_x] >= H[pos_y][pos_x])
        {
            up = false;
            break;
        }
    }

    // Check down
    for (int i = pos_y + 1; i <= size; i++)
    {
        if (H[i][pos_x] >= H[pos_y][pos_x])
        {
            down = false;
            break;
        }
    }

    // Check left
    for (int i = pos_x - 1; i >= 0; i--)
    {
        if (H[pos_y][i] >= H[pos_y][pos_x])
        {
            left = false;
            break;
        }
    }

    // Check right
    for (int i = pos_x + 1; i <= size; i++)
    {
        if (H[pos_y][i] >= H[pos_y][pos_x])
        {
            right = false;
            break;
        }
    }

    return up || down || left || right;
}

    int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> heights;
    vector<vector<bool>> visible;
    int totalVisible = 0; 

    // Input
    string s;
    int size = 0;
    int i = 0;
    while (getline(cin, s))
    {
        heights.push_back(vector<int>());
        visible.push_back(vector<bool>());

        size = s.size() - 1;
        stringstream ss(s);
        char h;
        while (ss >> h && h != ' ')
        {
            heights[i].push_back(atoi(&h));
            visible[i].push_back(false);
        }
        i++;
    }

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            if (i == 0 | j == 0 | i == size || j == size || isVisible(i, j, size, heights))
            {
                visible[j][i] = true;
                totalVisible++;
            }
        }
    }

    for (auto v : visible)
    {
        for (auto b : v)
        {
            cout << (b ? "1" : "0");
        }
        cout << endl;
    }
    cout << totalVisible << endl;

    return 0;
}