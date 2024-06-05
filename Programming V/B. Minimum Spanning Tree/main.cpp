//
//  main.cpp
//  B. Minimum Spanning Tree
//
//  Created by Majd Kawak on 11/20/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent(int a, vector<int> &root) {
    while(root[a] != a){
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b, vector<int> &root) {
    int d = parent(a, root);
    int e = parent(b, root);
    root[d] = root[e];
}

int main(int argc, const char * argv[]) {
    
    // Input Vertices number
    int num_Devices;
    cin >> num_Devices;
    
    // Input Edges number
    int num_Connections;
    cin >> num_Connections;
    
    // Minimum cost
    int minCost=0;
    
    // Edges in graph
    pair<int,pair<int,int>> k_Edges[num_Connections];
    
    // Input edges
    int v_1, v_2, val;
    for(int i = 0; i < num_Connections; i++){
        cin >> v_1;
        cin >> v_2;
        cin >> val;
        k_Edges[i]=make_pair(val, make_pair(v_1, v_2));
    }
    
    // Sort all edges
    sort(k_Edges, k_Edges+num_Connections);
    
    // Root tree
    vector<int> root(num_Devices);
    for(int i = 0; i < root.size(); i++) {
        root[i]=i;
    }
    
    // Compute using Kruskal's Algorithm
    for(int i = 0; i < num_Connections; i++) {
        
        int u = k_Edges[i].second.first;
        int v = k_Edges[i].second.second;
        int cost =  k_Edges[i].first;
        
        if(parent(u, root) != parent(v, root)) {
            minCost += cost;
            union_find(u, v, root);
        }
    }
    
    // Display result
    cout << minCost;
    
    return 0;
}
