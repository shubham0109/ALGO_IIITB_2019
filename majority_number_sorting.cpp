// MAJORITY ELEMENT USING SORTING O(NLOGN)

# include <iostream>
using namespace std;

int findLeftPos(int arr[], int lo, int hi, int ele, int prev_pos){
    if (lo > hi){
        return prev_pos;
    }
    
    int mid = (lo+hi)/2;
    
    int new_ele = arr[mid];
    if (new_ele == ele){
        if (lo == hi){
            return mid;
        }
        return findLeftPos(arr, lo, mid-1, ele, mid);
    }else{
        if (lo == hi){
            return prev_pos;
        }
        return findLeftPos(arr, mid+1, hi, ele, prev_pos);
    }
}

int findRightPos(int arr[], int lo, int hi, int ele, int prev_pos){
    if (lo > hi){
        return prev_pos;
    }
    
    int mid = (lo+hi)/2;
    
    int new_ele = arr[mid];
    if (new_ele == ele){
        if (lo == hi){
            return mid;
        }
        return findRightPos(arr, mid+1, hi, ele, mid);
    }else{
        if (lo == hi){
            return prev_pos;
        }
        return findRightPos(arr, lo, mid-1, ele, prev_pos);
    }
}

int main(){
    int n = 6;
    int arr[n+10];
    
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            arr[i] = 1;
        }else{
            arr[i] = i;
        }
    }
    
    sort(arr, arr+n);
    
    int lo = 0;
    int hi = n-1;
    
    int mid;
    
    mid = (lo+hi)/2;
    int ele = arr[mid];
    int left_pos = findLeftPos(arr, lo, mid-1, ele, mid);
    int right_pos = findRightPos(arr, mid+1, hi, ele, mid);
    int majority = right_pos - left_pos + 1;
        
    cout<<"No. of time it occurs: "<<majority<<endl;
    if (majority > n/2){
        cout<<"Majority element is: "<<arr[mid]<<endl;
    }else{
        cout<<"No majority"<<endl;
    }
    
    return 0;
}
