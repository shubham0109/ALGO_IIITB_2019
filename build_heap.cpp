# include <iostream>
using namespace std;

int main(){
    int n = 100;
    int arr[n+10];
    
    for (int i = 0; i < n; i++){
        arr[i] = n-i;
    }
    
    cout <<"The array is: ";
    
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
