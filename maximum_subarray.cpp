# include <iostream>
# include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 8;
    int a[9] = {-2, -5, 6, -2, -3, 1, 5, -6};
    
    cout<<"The array is: ";
    for (int i = 0; i < n; i++){
        //int num = rand()%n;
        //a[i] = num;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    int sum = 0;
    int mx_sum = INT_MIN;
    
    for (int i = 0; i < n; i++){
        sum += a[i];
        mx_sum = max(mx_sum, sum);
        if (sum < 0)sum = 0;
    }
    
    cout<<"Maximum subarray is: "<<mx_sum<<endl;
    
    return 0;
}
