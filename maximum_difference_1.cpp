// given arr = a0,a1,....,an
// find max(aj - ai) such that j > i


# include <iostream>
# include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 100;
    int arr[n+1];
    
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        arr[i] = num;
    }
    
    int i = 0;
    int mx = INT_MIN;
    for (int j = 1; j < n; j++){
        mx = max(mx, arr[j]-arr[i]);
        
        if (arr[j] < arr[i]){
            i = j;
        }
    }
    
    cout<<"max difference is: "<<mx<<endl;
    return 0;
}
