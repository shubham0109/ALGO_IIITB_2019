// DETERMINISTIC FIND RANK (rank = n/2; median)
// Here we divide n nos. into groups of n/5 or n/7 and so on, find medians of each of the group,
// find the medians of the medians, and use that as a pivot
// It deterministically solves in linear time

// SOME OBSERVATIONS
// N = 1000000 (1 MILLION)
// GRP_SIZE = 5, TIME_TAKEN = 69s
// GRP_SIZE = 7, TIME_TAKEN = 42.1s
// GRP_SIZE = 11, TIME_TAKEN = 32s
// GRP_SIZE = 101, TIME_TAKEN = 0.28s



# include <iostream>
# include <ctime>
# include <cstdlib>
using namespace std;

const int size = 1000000;
const int median = size/2;

int findRank(int arr[], int pivot_index, int lo, int hi){
    
    int index = lo+1;
    int pivot = arr[pivot_index];
    swap(arr[lo], arr[pivot_index]);
    for (int i = lo+1; i < hi; i++){
        if (arr[i] < pivot){
            swap(arr[index], arr[i]);
            index++;
        }
    }
    index--;
    swap(arr[index], arr[lo]);
    return index;
}

int getMedian(int arr[], int i, int grp_size){
    
    int last_pos = i + grp_size;
    
    for (int j = i; j < last_pos; j++){
        int min = arr[j];
        int ind = j;
        for (int k = j+1; k < last_pos; k++){
            if (arr[k] < min){
                min = arr[k];
                ind = k;
            }
        }
        
        swap(arr[j], arr[ind]);
    }
    
    return arr[i + grp_size/2];
}

int main(){
    int arr[size];
    srand(time(NULL));
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    
    for (int i = 0; i < size; i += 1){
        int num = rand()%size;
        //cout<<"num: "<<num<<endl;
        arr[i] = num;
        //arr[i+1] = i;
    }
    
    //cout<<"the array is: ";
    //for (int i = 0; i < size; i++)cout<<arr[i]<<" ";
    
    //cout<<endl;
    int grp_size = 5;
    int lo = 0;
    int hi = size;
    
    int ctr = 0;
    while (lo <= hi){
        ctr++;
        int median_pos = 0;
        for (int i = lo; i < hi; i += grp_size){
            if (hi - i < grp_size)break;
            int get_median  = getMedian(arr, i, grp_size);
            int median_index = i + (grp_size/2);
            swap(arr[median_pos], arr[median_index]);
            median_pos++;
        }
        
        int pivot_element = getMedian(arr, lo, median_pos);
        int pivot = lo + median_pos/2;
        //cout<<"pivot ele: "<<pivot_element<<endl;
        
        int index = findRank(arr, pivot, lo, hi);
        //cout<<"index: "<<index<<endl;
        if (index == median){
            cout<<"Found the median: "<<arr[index]<<endl;
            break;
        }else if (index < median){
            //Check in the right side
            //cout<<"right"<<endl;
            lo = index + 1;
        }else {
            //Check in the left side
            //cout<<"left"<<endl;
            hi = index;
        }
        
        //if (ctr == 5)break;
    }
    
    end = clock();
    
    cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
    
    cout<<"Total time taken: "<<cpu_time_used<<endl;
    
    return 0;
}
