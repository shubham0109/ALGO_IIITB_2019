// given arr = a0,a1,....,an
// find max(aj - ai) such that j > i+L


# include <iostream>
# include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 10;
    int arr[n+1];
    
    cout<<"the array is : ";
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        arr[i] = num;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int i = 0;
    int l = 2;
    int mx = INT_MIN;
    for (int j = l+1; j < n; j++){
        mx = max(mx, arr[j]-arr[i]);
        
        if (arr[j-l] < arr[i]){
            i = j-l;
        }
    }
    
    cout<<"max difference is: "<<mx<<endl;
    return 0;
}

