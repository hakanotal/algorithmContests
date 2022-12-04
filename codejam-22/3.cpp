// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>

using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";

        int N;
        cin >> N;
        vector<int> arr(N);
        int max_s = -1;
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
            max_s = max(max_s, arr[j]);
        }

        sort(arr.begin(), arr.end());
        queue<int> Q;
        for (int x : arr)
            Q.push(x);

        int limit = min(N, max_s);
        int index = 1;

        for(int k=0; k<N; k++){
            int last = Q.front();
            Q.pop();
            
            if(last >= index)
                index++;
            
            if(index > max_s)
                break;
        }
        cout << index-1 << endl;
    }

    return 0;
}