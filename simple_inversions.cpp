// O(N^2)

# include <iostream>
# include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 10;
    int arr[n+1];
    
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        arr[i] = num;
    }
    
    int ctr = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (arr[i] > arr[j])ctr++;
        }
    }
    
    cout<<ctr<<endl;
    return 0;
}
