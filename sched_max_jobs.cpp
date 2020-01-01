//
// Created by Shubham Kumar on 23/10/19.
//

// SCHEDULE MAXIMUM JOBS
// sort according to finish times, then pick

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>

using namespace std;

bool f(pair <int, int> p1, pair <int, int> p2){
    return p1.second < p2.second;
}

int main(){
    int jobs = 5;

    vector <pair <int, int> > v;

    int ctr = 0;

    cout<<"Enter starting and finishing time for each job\n";
    for (int i = 0; i < jobs; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), f);

    int fin = INT_MIN;
    for (int i = 0; i < v.size(); i++){
        if (v[i].first >= fin){
            ctr++;
            fin = v[i].second;
        }
    }
    cout<<"The maximum no.of jobs that can be scheduled are : "<<ctr<<endl;

    return 0;
}