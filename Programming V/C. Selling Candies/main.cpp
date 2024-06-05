//
//  main.cpp
//  C. Selling Candies
//
//  Created by Majd Kawak on 11/20/22.
//
 
#include <iostream>
#include <list>
#include <vector>
#include <queue>

// #define int long long

using namespace std;
 
void add_Edge(list<pair<int,int>> *adj_List, int u, int v, int w) {
    
    adj_List[u].push_back(make_pair(v,w));
}
 
void compute_Dijkstra(list<pair<int,int>> *adj_List, int s, int &num_Cities, vector<int> &distance){
    
    // Prioirty queue to hold Edges(W_e, V_e)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    
    // Push all Edges connected to s
    for(list<pair<int,int>> :: iterator it = adj_List[0].begin(); it != adj_List[0].end(); it++) {
        pq.push(make_pair(it->second, it->first));
        distance[it->first] = it->second;
    }
    
    // Source distance to itself is 0
    distance[s] = 0;
    
    // While all vertcies not connected
    while (!pq.empty()) {
        
        // Extract min from Prioirty queue
        int u = pq.top().second;
        
        // Distance to u from s
        int dist = pq.top().first;
        
        // Pop min edge from queue
        pq.pop();
        
        if (dist > distance[u]) continue;
        
        // Go though all adjacent vertices of u
        for(list<pair<int,int>> :: iterator it = adj_List[u].begin(); it != adj_List[u].end(); it++) {
            
            // Get vertex number and weight of current adjacent of u
            int v = it->first;
            int weight = it->second;
            
            // If there is shorted path to v through u.
            if (distance[v] > distance[u] + weight) {
                // Updating distance of v
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}
 
int32_t main(int argc, const char * argv[]) {
    
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Input Vertices number
    int num_Cities;
    cin >> num_Cities;
    
    // Input Edges number
    int num_Roads;
    cin >> num_Roads;
     
    // Selling special candy at each city value
    int candy_Val;
    vector<int> candy_Profit(num_Cities);
    for(int i = 0; i < num_Cities; i++){
        cin >> candy_Val;
        candy_Profit[i]=candy_Val;
    }
    
    // Graph using adjacency list
    list<pair<int,int>> *adj_List_Original = new list<pair<int, int>>[num_Cities];
    list<pair<int,int>> *adj_List_Inverse = new list<pair<int, int>>[num_Cities];
    
    // Input edges
    int city_1, city_2, distance_Val;
    for(int i = 0; i < num_Roads; i++){
        cin >> city_1;
        cin >> city_2;
        cin >> distance_Val;
        add_Edge(adj_List_Original, city_1, city_2, distance_Val);
        add_Edge(adj_List_Inverse, city_2, city_1, distance_Val);
    }
    
    // Vector with calculated minimum distance from source and
    // Vector with calculated minimum distance to source
    vector<int> distance_From_Source(num_Cities, INT_MAX);
    vector<int> distance_To_Source(num_Cities, INT_MAX);
 
    compute_Dijkstra(adj_List_Original, 0, num_Cities, distance_From_Source);
    compute_Dijkstra(adj_List_Inverse, 0, num_Cities, distance_To_Source);
    
    int max_Profit =  candy_Profit[0];
    // Compute profit
    for(int i = 1; i < num_Cities; i++){
        if(distance_To_Source[i]<INT_MAX && distance_From_Source[i]<INT_MAX){
            candy_Profit[i] = candy_Profit[i]-(distance_From_Source[i]+distance_To_Source[i]);
            max_Profit = (max_Profit < candy_Profit[i]) ? candy_Profit[i] : max_Profit;
        }
    }
    
    //Display result
    cout << max_Profit;
    
    /*
    // Delete
    delete[] adj_List_Original;
    delete[] adj_List_Inverse;
    */
    return 0;
}
