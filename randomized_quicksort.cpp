// RANDOMIZED QUICKSORT
// takes in a random pivot
// average case O(nlogn)
// experimentally found out to be 3 or 4 times better than merge sort

# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>
using namespace std;

int partition(vector <int> &v, int lo, int hi){
    
    int size = hi - lo + 1;
    int n = rand();
    int pivot = lo +  (rand()%size);
    int pivot_element = v[pivot];
    swap(v[lo], v[pivot]);
    int index = lo+1;
    
    for (int i = lo+1; i <= hi; i++){
        if (v[i] < pivot_element){
            swap(v[i],v[index]);
            index++;
        }
    }
    index--;
    swap(v[lo],v[index]);
    return index;
}

void quicksort(vector <int> &v, int lo, int hi){
    
    if (lo >= hi)return;
    int index = partition(v, lo, hi);
    
    quicksort(v, lo, index-1);
    quicksort(v, index+1, hi);
}

int main(){
    srand(time(NULL));
    vector <int> v;
    
    int n = 10;
    
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        v.push_back(num);
    }
    
    cout<<"The original array is: ";
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    quicksort(v, 0, n-1);
    
    cout<<"The sorted array is: ";
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
