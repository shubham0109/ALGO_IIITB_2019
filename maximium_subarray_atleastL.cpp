// MAXIMUM SUBARRAY OF SIZE ATLEAST L

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
    
    int mx_sum = INT_MIN;
    int sub_sum[n+10];
    memset(sub_sum, 0, sizeof(sub_sum));
    sub_sum[0] = a[0];
    mx_sum = a[0];
    
    for (int i = 1; i < n; i++){
        mx_sum = max(a[i], mx_sum + a[i]);
        sub_sum[i] = mx_sum;
    }
    
    
    int sum = 0;
    int l = 4;

    for (int i = 0; i < l; i++){
        sum += a[i];
    }
    int result = sum;
    
    for (int i = l; i < n; i++){
        sum += a[i];
        sum -= a[i-l];
        
        result = max(result, sum);
        
        result = max(result, sum + sub_sum[i-l]);
    }
    
    cout<<"Maximum subarray with atleat L size is: "<<result<<endl;
    
    return 0;
}

