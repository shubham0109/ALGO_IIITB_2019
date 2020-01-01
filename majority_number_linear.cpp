// LINEAR ALGORITHM O(N)

# include <iostream>
using namespace std;

int main(){
    int n = 100;
    int arr[n+10];
    
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            arr[i] = 1111;
        }else{
            arr[i] = i;
        }
    }
    
    int ctr = 1;
    int ele = arr[0];
    
    for (int i = 1; i < n; i++){
        if (arr[i] == ele){
            ctr++;
        }else{
            if (ctr > 0){
                ctr--;
            }else{
                ctr = 1;
                ele = arr[i];
            }
        }
    }
    
    ctr = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == ele){
            ctr++;
        }
    }
    
    if (ctr > n/2){
        cout<<"Majority element is: "<<ele<<endl;
    }else{
        cout<<"No majority element"<<endl;
    }
    
    return 0;
}
