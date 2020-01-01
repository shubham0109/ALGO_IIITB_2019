//
// Created by Shubham Kumar on 01/11/19.
//
// STRONGLY CONNECTED COMPONENTS
// USED TRANSPOSE PROPERTY OF SCC

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

void dfs(int i, vector <int> adj[], bool vis[], stack <int>& st){

    vis[i] = true;

    for (int j = 0; j < adj[i].size(); j++){
        int node = adj[i][j];

        if (vis[node] == false){
            dfs(node, adj, vis, st);
        }
    }

    st.push(i);
}

void printscc(int node, vector <int> tr_adj[], bool vis[]){
    vis[node] = true;

    for (int i = 0; i < tr_adj[node].size(); i++){
        int nd = tr_adj[node][i];

        if (vis[nd] == false){
            printscc(nd, tr_adj, vis);
        }
    }

    cout<<node<<" ";

}

int main(){
    int v = 5;
    vector <int> adj[v+10];

    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);
    adj[0].push_back(2);
    adj[2].push_back(1);

    bool vis[6] = {false};

    stack <int> st;

    for (int i = 0; i < 5; i++){
        if (vis[i] == false){
            dfs(i, adj, vis, st);
        }
    }

    // now transpose the graph
    vector <int> tr_adj[v+10];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < adj[i].size(); j++){
            int nd = adj[i][j];
            tr_adj[nd].push_back(i);
        }
    }

    for (int i = 0; i < 5; i++)vis[i] = false;

    while (!st.empty()){
        int node = st.top();
        st.pop();
        if (vis[node] == true)continue;

        printscc(node, tr_adj, vis);
        cout<<endl;
    }


}