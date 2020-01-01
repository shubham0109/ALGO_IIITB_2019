// BUILD A HEAP: O(N)

# include <iostream>
using namespace std;

void heapify (int a[], int k, int sz){
    if (k > ((sz/2)-1)){
        return;
    }
    
    int parent = k;
    int left_child = 2*k + 1;
    int right_child = 2*k + 2;
    
    
    int largest = parent;
    
    if (left_child <= sz-1 && a[left_child] < a[largest]){
        largest = left_child;
    }
    
    if (right_child <= sz-1 && a[right_child] < a[largest]){
        largest = right_child;
    }
    
    if (largest != parent){
        swap(a[parent], a[largest]);
        heapify(a, largest, sz);
    }
}


int delete_min(int a[], int &n){
    int min_ele = a[0];
    swap(a[0], a[n-1]);
    n = n-1;
    heapify(a, 0, n);
    
    return min_ele;
}

int main(){
    int n = 10;
    int a[n+10];
    
    cout<<"The array is: ";
    for (int i = 0; i < n; i++){
        a[i] = n-i;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    
    // BUILD A HEAP
    int k = (n/2) - 1;
    
    while(k >= 0){
        heapify(a,k,n);
        k--;
    }
    
    cout<<"The MIN-HEAP is: ";
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    
    // DELETE MIN
    int min_ele = delete_min(a, n);
    cout<<"The minimum element is: "<<min_ele<<endl;
    
    cout<<"The MIN-HEAP after DELETE_MIN is: ";
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
