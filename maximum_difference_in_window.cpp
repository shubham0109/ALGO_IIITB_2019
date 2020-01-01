// given arr = a0,a1,....,an
// find max(aj - ai) such that j is in a window of L


# include <iostream>
# include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 12;
    int arr[13] = {10, 9, 3, 4, 9, 8, 6, 1, 4, 3, 2, 1};
    
    cout<<"the array is : ";
    for (int i = 0; i < n; i++){
        //int num = rand()%n;
        //arr[i] = num;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //int i = 0;
    int l = 3;
    int m[n+1];
    m[0] = -1;
    m[1] = 0;
    for (int i = 2; i < n; i++){
        int mn = INT_MAX;
        int min_ind;
        for (int k = 1; k <= l; k++){
            if (i - k >= 0){
                if (arr[i-k] < mn)
                    min_ind = i-k;
                mn = arr[i-k];
            }
        }
        m[i] = min_ind;
    }
    
    int mx = INT_MIN;
    for (int j = 1; j < n; j++){
        cout<<m[j]<<" ";
        int min_ind = m[j];
        mx = max(mx, arr[j]-arr[min_ind]);
    }
    cout<<endl;
    
    cout<<"max difference is: "<<mx<<endl;
    return 0;
}


