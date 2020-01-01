//
// Created by Shubham Kumar on 16/11/19.
//

# include <iostream>
# include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int a[n+10][m+10];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }




    // upper left
    int dp1[n+10][m+10];
    int dps1[n+10][m+10];
    for (int i = 0; i < m; i++){
        if (a[0][i] == 1){
            dp1[0][i] = 1;
            dps1[0][i] = 1;
        }else{
            dp1[0][i] = 0;
            dps1[0][i] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i][0] == 1){
            dp1[i][0] = 1;
            dps1[i][0] = 1;
            if (i > 0){
                dps1[i][0] += dps1[i-1][0];
            }
        }else{
            dp1[i][0] = 0;
            dps1[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] == 0){
                dp1[i][j] = 0;
                dps1[i][j] = 0;
            }else{
                dp1[i][j] = 1 + dp1[i-1][j-1];
                dps1[i][j] = 1 + dps1[i-1][j];
            }
        }
    }

    // upper right
    int dp2[n+10][m+10];
    int dps2[n+10][m+10];
    for (int i = m-1; i >= 0; i--){
        if (a[0][i] == 1){
            dp2[0][i] = 1;
            dps2[0][i] = 1;
            if (i < m-1){
                dps2[0][i]  += dps2[0][i+1];
            }
        }else{
            dp2[0][i] = 0;
            dps2[0][i] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i][m-1] == 1){
            dp2[i][m-1] = 1;
            dps2[i][m-1] = 1;
        }else{
            dp2[i][m-1] = 0;
            dps2[i][m-1] = 0;
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = m-2; j >= 0; j--){
            if (a[i][j] == 0){
                dp2[i][j] = 0;
                dps2[i][j] = 0;
            }else{
                dp2[i][j] = 1 + dp2[i-1][j+1];
                dps2[i][j] = 1 + dps2[i][j+1];
            }
        }
    }

    // lower left
    int dp3[n+10][m+10];
    int dps3[n+10][m+10];
    for (int i = 0; i < m; i++){
        if (a[n-1][i] == 1){
            dp3[n-1][i] = 1;
            dps3[n-1][i] = 1;

            if (i > 0){
                dps3[n-1][i] += dps3[n-1][i-1];
            }

        }else{
            dp3[n-1][i] = 0;
            dps3[n-1][i] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i][0] == 1){
            dp3[i][0] = 1;
            dps3[i][0] = 1;
        }else{
            dp3[i][0] = 0;
            dps3[i][0] = 0;
        }
    }

    for (int i = n-2; i >= 0; i--){
        for (int j = 1; j < m; j++){
            if (a[i][j] == 0){
                dp3[i][j] = 0;
                dps3[i][j] = 0;
            }else{
                dp3[i][j] = 1 + dp3[i+1][j-1];
                dps3[i][j] = 1 + dps3[i][j-1];
            }
        }
    }

    // lower right
    int dp4[n+10][m+10];
    int dps4[n+10][m+10];
    for (int i = 0; i < m; i++){
        if (a[n-1][i] == 1){
            dp4[n-1][i] = 1;
            dps4[n-1][i] = 1;
        }else{
            dp4[n-1][i] = 0;
            dps4[n-1][i] = 0;
        }
    }

    for (int i = n-1; i >= 0; i--){
        if (a[i][m-1] == 1){
            dp4[i][m-1] = 1;
            dps4[i][m-1] = 1;
            if (i < n-1){
                dps4[i][m-1] += dps4[i+1][m-1];
            }
        }else{
            dp4[i][m-1] = 0;
            dps4[i][m-1] = 0;
        }
    }

    for (int i = n-2; i >= 0; i--){
        for (int j = m-2; j >= 0; j--){
            if (a[i][j] == 0){
                dp4[i][j] = 0;
                dps4[i][j] = 0;
            }else{
                dp4[i][j] = 1 + dp4[i+1][j+1];
                dps4[i][j] = 1 + dps4[i+1][j];
            }
        }
    }



    // solve
    int mx_len = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == 0)continue;
            if (i == 0 || j == 0 || i == n-1 || j == m-1)continue;

            if (a[i-1][j] == 0 || a[i+1][j] == 0 || a[i][j+1] == 0 || a[i][j-1] == 0)continue;

            int l = dp1[i][j] + dp2[i][j] + dp3[i][j] + dp4[i][j] - 3;

            mx_len = max(mx_len, l);

        }
    }

    cout<<"dp1: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<dps1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"dp2: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<dps2[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"dp3: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<dps3[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"dp4: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<dps4[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"length: "<<mx_len<<endl;
}

