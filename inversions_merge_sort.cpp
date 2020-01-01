// O(NLOGN)
// Inversion Pairs: i < j && a[i] > a[j]

# include <iostream>
# include <ctime>
using namespace std;

int merge(int arr[], int lo, int mid, int hi){
    int l = lo;
    int r = mid+1;
    int ctr = 0;
    int k = 0;
    int dummy_arr[hi+10];
    
    while (l <= mid && r <= hi){
        if (arr[l] <= arr[r]){
            dummy_arr[k++] = arr[l];
            l++;
        }else{
            dummy_arr[k++] = arr[r];
            ctr += mid - l + 1;
            r++;
        }
    }
    
    while (l <= mid){
        dummy_arr[k++] = arr[l++];
    }
    
    while (r <= hi){
        dummy_arr[k++] = arr[r++];
    }
    
    k = 0;
    for (int i = lo; i <= hi; i++){
        arr[i] = dummy_arr[k++];
    }
    
    return ctr;
}

int merge_inversion(int arr[], int lo, int hi){
    
    if (lo < hi){
        int mid = (lo + hi)/2;
        
        return merge_inversion(arr, lo, mid) + merge_inversion(arr, mid+1, hi) + merge(arr, lo, mid, hi);
    }
    
    return 0;
}

int main(){
    srand(time(NULL));
    int n = 10;
    int arr[n+1];
    
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        arr[i] = num;
    }
    
    cout<<"The array is: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int lo = 0;
    int hi = n-1;
    
    cout<<"The no. of inversions = "<<merge_inversion(arr, lo, hi)<<endl;
}
