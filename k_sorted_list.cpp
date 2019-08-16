# include <iostream>
# include <queue>
# include <algorithm>
# include <ctime>
using namespace std;

typedef pair <int, pair <int, int> > ele;

int main(){
    srand(time(NULL));
    int k = 10;
    vector <int> l[k+1];
    
    int ind = 0;
    int ctr = k;
    for (int i = 1; i <= 100; i++){
        int n = rand()%100;
        l[ind].push_back(n);
        ctr--;
        if (ctr == 0){
            sort(l[ind].begin(), l[ind].end());
            ctr = k;
            ind++;
        }
    }
    
    priority_queue <ele, vector<ele>, greater<ele> > min_heap;
    
    for (int i = 0; i < k; i++){
        int num = l[i][0];
        ele e = make_pair(num, make_pair(i, 0));
        min_heap.push(e);
    }
    
    vector <int> sorted;
    
    while(!min_heap.empty()){
        ele min_e = min_heap.top();
        min_heap.pop();
        sorted.push_back(min_e.first);
        
        int arr_no = min_e.second.first;
        int arr_ind = min_e.second.second;
        
        if (arr_ind < l[arr_no].size()-1){
            arr_ind++;
            int num = l[arr_no][arr_ind];
            ele e = make_pair(num, make_pair(arr_no, arr_ind));
            min_heap.push(e);
        }
    }
    
    cout<<"The sorted array is: ";
    for (int i = 0; i < sorted.size(); i++){
        cout<<sorted[i]<<" ";
    }
    
    return 0;
}
