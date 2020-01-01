// given arr = a0,a1,....,an
// find max(aj - ai) such that j is in a window of w
// faster algo: linear

# include <iostream>
# include <ctime>
# include <stack>
# include <queue>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 12;
    int arr[n+1];
    
    cout<<"the array is : ";
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        arr[i] = num;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int mx = INT_MIN;
    int w = 3;
    int s[n+10];
    int l = 0;
    int r = 0;
    s[0] = 0;
    
    for (int j = 1; j < n; j++){
        int num = arr[j];
        while (j - s[l] > w)l++;
        
        int diff = num - arr[s[l]];
        mx =  max(diff, mx);
        
        while(r >= l && num < arr[s[r]]){
            r--;
        }
        r++;
        s[r] = j;
    }
    cout<<"max difference is: "<<mx<<endl;
    return 0;
}



