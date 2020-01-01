// MAXIMUM SUBARRAY OF SIZE ATMOST L

# include <iostream>
# include <ctime>
# include <cstring>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 5;
    int a[9] = {1, 2, 3, -10, -3};
    
    cout<<"The array is: ";
    for (int i = 0; i < n; i++){
        //int num = rand()%n;
        //a[i] = num;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    int mx_sum[n+10];
    memset(mx_sum, 0, sizeof(mx_sum));
    mx_sum[0] = a[0];
    int l = 4;
    int res = mx_sum[0];
    int sum;
    
    for (int i = 1; i < n; i++){
        if (i - l >= 0){
            int st = i-l+1;
            //mx_sum = a[st];
            sum = a[st];
            for (int j = st+1; j <= i; j++){
                //sum += a[j];
                sum = max(sum + a[j], sum);
                //mx_sum[j] =
            }
            mx_sum[i] = sum;
        }else{
            //mx_sum = a[0];
            sum = a[0];
            for (int j = 1; j <= i; j++){
                //sum += a[j];
                sum = max(sum + a[j], sum);
                //mx_sum[j] =
            }
            mx_sum[i] = sum;
        }
        
        res = max(res, mx_sum[i]);
    }
    
    
    cout<<"Maximum subarray with atmost L size is: "<<res<<endl;
    
    return 0;
}


