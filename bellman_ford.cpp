// BELLMAN FORD ALGO: single source shortest simple path  O(VE)

# include <iostream>
# include <vector>
# include <cstring>
# include <cstdlib>

using namespace std;

vector <int> bellman_ford(vector < pair <int, pair<int, int> > > adj, int src, int nodes, int e){
    
    // dist vector to store shortest path
    vector <int> dist(nodes+1);
    
    // initialize all to infinity
    for (int i = 0; i < nodes+1; i++){
        dist[i] = INT_MAX;
    }
    
    // initialize the source to 0
    dist[src] = 0;
    
    
    // bellman ford algo
    
    for (int i = 1; i <= nodes-1; i++){
        for (int j = 0; j < e; j++){
            pair <int, pair<int, int> > p = adj[j];
            
            int weight = p.first;
            pair <int, int> co_ordinates = p.second;
            
            int u = co_ordinates.first;
            int v = co_ordinates.second;
            
            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    // detect negative cycles
    bool flag = false;
    for (int j = 0; j < e; j++){
        pair <int, pair<int, int> > p = adj[j];
        
        int weight = p.first;
        pair <int, int> co_ordinates = p.second;
        
        int u = co_ordinates.first;
        int v = co_ordinates.second;
        
        if (dist[u] + weight < dist[v]){
            cout<<"there is a negative cycle\n";
            flag = true;
            break;
        }
    }
    
    if (flag){
        for (int i = 0; i <= nodes; i++){
            dist[i] = -1;
        }
    }
    
    return dist;
}

int main(){
    
    int n = 5;   // no. of vertices (0, 1, 2, 3, 4)
    int e = 8;  //  no. of edges
    
    // edge list : {weight, src, dest}
    vector < pair <int, pair<int, int> > > adj;
    
    // push all the edges in edge list
    adj.push_back(make_pair(1, make_pair(0, 1)));
    adj.push_back(make_pair(4, make_pair(0, 2)));
    adj.push_back(make_pair(3, make_pair(1, 2)));
    adj.push_back(make_pair(2, make_pair(1, 3)));
    adj.push_back(make_pair(2, make_pair(1, 4)));
    adj.push_back(make_pair(5, make_pair(3, 2)));
    adj.push_back(make_pair(1, make_pair(3, 1)));
    adj.push_back(make_pair(3, make_pair(4, 3)));
    
    
    
    // bellman ford
    int src = 0;
    vector <int> dist = bellman_ford(adj, src, n, e);
    
    
    cout<<"Vertices\t\tShortest Path\n";
    
    for (int i = 0; i < n; i++){
        cout<<i<<"\t\t\t"<<dist[i]<<endl;
    }
    
    return 0;
}
