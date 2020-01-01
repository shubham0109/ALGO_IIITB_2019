// FLOYD WARSHALL ALGO: all pair shortest simple path  O(V^3)

# include <iostream>
# include <vector>
# include <cstring>
# include <cstdlib>
# define inf 9999


using namespace std;

void floyd_warshall(int dist[][6], int adj[][6], int nodes){
    
    // initialize the distances
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            dist[i][j] = adj[i][j];
        }
    }
    
    // floyd warshall algo
    
    for (int k = 0; k < nodes; k++){
        for (int i = 0; i < nodes; i++){
            for (int j = 0; j < nodes; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    
    
    // detect negative cycles : check if dist to itself is negative
    bool flag = false;
    for (int j = 0; j < nodes; j++){
        if (dist[j][j] < 0){
            cout<<"there is a negative cycle\n";
            flag = true;
            break;
        }
    }
    
    if (flag){
        for (int i = 0; i < nodes; i++){
            for (int j = 0; j < nodes; j++){
                dist[i][j] = -1;
            }
        }
    }
}

int main(){
    
    int n = 4;   // no. of vertices (0, 1, 2, 3, 4)
    
    // adjacenecy matrix
    int adj[6][6];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                adj[i][j] = 0;
            }else{
                adj[i][j] = inf;
            }
        }
    }
    
    
    // get the edges
    adj[0][1] = 5;
    adj[0][3] = 10;
    adj[1][2] = 3;
    adj[2][3] = 1;
    adj[1][0] = 6;
    
    
    // floyd warshall
    int dist[6][6];
    floyd_warshall(dist, adj, n);
    
    
    cout<<"All Pair Shortest Path\n";
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] == inf){
                cout<<"inf\t";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    
    return 0;
}

