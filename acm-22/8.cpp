#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int64_t n, a, r = 0;

priority_queue<int> p;

int main()
{
    for (cin >> n; n--;)
        cin >> a, a += n, p.push(a), p.push(a), r += p.top() - a, p.pop();
    cout << r;
    return 0;
}