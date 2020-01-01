//
// Created by Shubham Kumar on 23/10/19.
//

// SCHEDULE ALL JOBS
// sort according to the start time
// depth gives the maximum no. of resource required


# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <queue>

using  namespace std;

bool f(pair <int, int> p1, pair <int, int> p2){
    return p1.first < p2.first;
}


class myComparator{
public:
    bool operator()(pair <int, int> &p1, pair <int, int> &p2){
        return p1.second > p2.second;
    }
};

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

    // use min heap to store the finish time of every job
    priority_queue<pair<int, int>, vector<pair<int, int> >, myComparator > pq;

    int mc = 1;
    int machines[jobs+1];

    pq.push(make_pair(mc, v[0].second));
    machines[0] = mc;

    for (int i = 1; i < jobs; i++){
        pair <int, int> p = pq.top();
        if (p.second <= v[i].first){
            int m_no = p.first;
            pq.pop();
            pq.push(make_pair(m_no, v[i].second));
            machines[i] = m_no;
        }else{
            mc++;
            pq.push(make_pair(mc, v[i].second));
            machines[i] = mc;
        }
    }


    cout<<"The jobs could be scheduled as follows: \n";
    for (int i = 0; i < jobs; i++){
        cout<<"process: "<<i+1<<" machine: M"<<machines[i]<<endl;
    }

    return 0;
}
