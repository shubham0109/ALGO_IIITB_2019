// find a no. with rank less than n/2 (n = 1million)
// randomized algo takes less than 20 comparisons(usually 4 or less)
// in this case we took random 1 million nos. and inserted it into array


# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

int find_rank(int arr[], int random_index){

    int pivot = arr[random_index];
    swap(arr[0], arr[random_index]);
    
    int index = 1;
    
    for (int i = 1; i < 1000000; i++){
        if (arr[i] <= pivot){
            swap(arr[index], arr[i]);
            index++;
        }
    }
    index--;
    swap(arr[0],arr[index]);
    return index+1;
}

int main(){
    srand(time(NULL));
    int arr[1000000];
    int n = 1000000;
    
    for (int i = 0; i < n; i++){
        int num = rand();
        arr[i] = num;
    }
    
    int no_of_comparisons = 0;
    
    while(true){
        int random_index = rand()%1000000;
        int rank = find_rank(arr, random_index);
        no_of_comparisons++;
        if (rank < n/2){
            break;
        }
    }
    
    cout<<"NO. OF COMPARISONS: "<<no_of_comparisons<<endl;
    
    return 0;
}
