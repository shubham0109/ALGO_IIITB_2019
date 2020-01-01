# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;



int main(){
    int n;
    cin>>n;
    
    int s[n+10];
    
    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        s[i] = x;
    }
    
    int dp[n+10][n+10];
    
    
    memset(dp, 0, sizeof(dp));
    
    for (int l = 1; l <= n; l++){
        for (int i = 0, j = l-1; j < n; i++, j++){
            if (l == 1){
                dp[i][j] = 1;
            }else{
                dp[i][j] = 1 + dp[i+1][j];
                if (s[i] == s[i+1]){
                    dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);
                }
                
                int k;
                for (k = i+2; k <= j; k++){
                    if (s[i] == s[k]){
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k+1][j]);
                    }
                }
                
                
            }
        }
    }
    
    cout<<dp[0][n-1]<<endl;
}
