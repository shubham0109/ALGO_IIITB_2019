# include <iostream>
# include <vector>

using namespace std;

bool comp(vector <int> a, vector <int> b){
    if (a[0] < b[0])return true;
    
    if (a[0] == b[0]){
        if (a[1] < b[1]){
            return true;
        }
    }
    
    return false;
}

int main(){
    int n;
    cin>>n;
    
    vector <int> arr[n+10];
    
    for (int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    
    sort(arr, arr + n, comp);
    
    
    int min = arr[0][1];
    int cnt = 0;
    
    for (int i = 1; i < n; i++){
        if (arr[i][1] >= min){
            cnt++;
        }else{
            min = arr[i][1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}

