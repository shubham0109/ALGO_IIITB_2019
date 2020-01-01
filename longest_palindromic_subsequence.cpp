# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;

string longestCommonSubsequence(string s, string r){
    int ls = s.size();
    int rs = r.size();
    
    int dp[ls+10][rs+10];
    memset(dp, 0, sizeof(dp));
    
    string lcs = "";
    for (int i = 0; i < ls; i++){
        for (int j = 0; j < rs; j++){
            if (s[i] == r[j]){
                dp[i+1][j+1] = 1 + dp[i][j];
                //lcs += s[i];
            }else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    
    int mx_len = 0;
    for (int i = 0; i <= ls; i++){
        for (int j = 0; j <= rs; j++){
            if (dp[i][j] > mx_len){
                mx_len++;
                lcs += s[i-1];
            }
        }
    }
    return lcs;
}

string longestPalindromeSubsequence(string s) {
    
    string r = s;
    reverse(r.begin(), r.end());
    string lcs = longestCommonSubsequence(s,r);
    
    return lcs;
}

int main(){
    string s = "1234121";
    cout<<longestPalindromeSubsequence(s)<<endl;
    
    return 0;
}

