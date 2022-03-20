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
    int n, x, y, dir;
    cin >> n;
    cin >> x >> y;
    cin >> dir;
    int ans = 1,head = 2,dual=3;
    int left,right;
    
        switch (dir)
        {
        case 0:
        for(int i=0;i<n-1;i++){
            if(y==0 || y == n){
                    ans += head;
                    head++;
            }
            
            else{
                right = y+1;
                left = y-1;
                for(int i=0;i<n-1;i++){
                    right -=1;
                    left +=1;
                    if(left<=0 || left >= n || right <=0 || right >=n){
                        ans += head;
                        head++;
                    }
                    else{
                        ans+= dual;
                        dual+=2;
                    }
                }
            }
        }
            break;
            case 1:
            for(int i=0;i<n-1;i++){
            if(x==0 || x == n){
                    ans += head;
                    head++;
            }
            
            else{
                right = x+1;
                left = x-1;
                for(int i=0;i<n-1;i++){
                    right -=1;
                    left +=1;
                    if(left<=0 || left >= n || right <=0 || right >=n){
                        ans += head;
                        head++;
                    }
                    else{
                        ans+= dual;
                        dual+=2;
                    }
                }
            }
        }
            break;
            case 2:
            for(int i=0;i<n-1;i++){
            if(y==0 || y == n){
                    ans += head;
                    head++;
            }
            
            else{
                right = y+1;
                left = y-1;
                for(int i=0;i<n-1;i++){
                    right -=1;
                    left +=1;
                    if(left<=0 || left >= n || right <=0 || right >=n){
                        ans += head;
                        head++;
                    }
                    else{
                        ans+= dual;
                        dual+=2;
                    }
                }
            }
            
            break;
            case 3:
            for(int i=0;i<n-1;i++){
            if(x==0 || x == n){
                    ans += head;
                    head++;
            }
            
            else{
                right = x+1;
                left = x-1;
                for(int i=0;i<n-1;i++){
                    right -=1;
                    left +=1;
                    if(left<=0 || left >= n || right <=0 || right >=n){
                        ans += head;
                        head++;
                    }
                    else{
                        ans+= dual;
                        dual+=2;
                    }
                }
            }
        }
        break;
        
        default:
            break;
        }
        cout << ans;
    

     

    return 0;
}