# include <iostream>
using namespace std;
const int mx = 1000100;

int main(){
    int n;
    cin>>n;
    
    int a[1000100] = {0};
    
    for (int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        a[x] = y;
    }
    
    int dp[1000100] = {0};
    
    for (int i = 0; < n; i++){
        if (a[i] = 0){
            dp[i] = dp[i-1];
        }
    }
}
