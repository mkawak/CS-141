//
//  main.cpp
//  D. Add Oil
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

void union_find(int a, int b, vector<int> &root, int &root_Num) {
    int d = parent(a, root);
    int e = parent(b, root);
    root[d] = root[e];
    root_Num--;
}

int main(int argc, const char * argv[]) {
    
    // Input Vertices number
    int num_Cities;
    cin >> num_Cities;
    
    // Input Edges number
    int num_Roads;
    cin >> num_Roads;
    
    // Minimum gas tank capacity
    int min_Capacity=0;
    
    // Edges in graph
    pair<int,pair<int,int>> roads[num_Roads];
    
    // Input edges
    int v_1, v_2, val;
    for(int i = 0; i < num_Roads; i++){
        cin >> v_1;
        cin >> v_2;
        cin >> val;
        roads[i]=make_pair(val, make_pair(v_1, v_2));
    }
    
    // Sort all edges
    sort(roads, roads+num_Roads);
    
    // Root tree
    vector<int> root(num_Cities);
    for(int i = 0; i < root.size(); i++) {
        root[i]=i;
    }
    
    int root_Num = num_Cities;
    
    // Compute using Kruskal's Algorithm
    for(int i = 0; i < num_Roads; i++) {
        
        int u = roads[i].second.first;
        int v = roads[i].second.second;
        int cost =  roads[i].first;
        
        if(parent(u, root) != parent(v, root)) {
            min_Capacity = cost;
            union_find(u, v, root, root_Num);
        }
        if(root_Num==1){
            break;
        }
    }
    
    // Display result
    cout << min_Capacity;
    
    return 0;
}
