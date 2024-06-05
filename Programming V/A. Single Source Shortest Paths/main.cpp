//
//  main.cpp
//  A. Single Source Shortest Paths
//
//  Created by Majd Kawak on 11/19/22.
//
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Return unvisited vetrtex with min distance
int get_Min_Dis(vector<int> &distance, vector<bool> &visited) {
    
    int min = INT_MAX;
    int min_Vertex_Index;
    for(int i = 0; i < distance.size(); i++) {
        if(distance[i] <= min && visited[i] == false) {
            min = distance[i];
            min_Vertex_Index=i;
        }
    }
    return min_Vertex_Index;
}
 
int main(int argc, const char * argv[]) {
    
    // Input Vertices number
    int num_Cities;
    cin >> num_Cities;
    
    // Input Edges number
    int num_Roads;
    cin >> num_Roads;
    
    // Input Source vertex
    int source_Vertex;
    cin >> source_Vertex;
    
    // Input Destination vertex
    int destination_Vertex;
    cin >> destination_Vertex;
    
    // Graph using 2D Matrix
    vector<vector<int>>  graph_Map(num_Cities, vector<int>(num_Cities, INT_MAX));
    
    // Input edges
    int city_1, city_2, distance_Val;
    for(int i = 0; i < num_Roads; i++){
        cin >> city_1;
        cin >> city_2;
        cin >> distance_Val;
        graph_Map[city_1][city_2] = distance_Val;
        graph_Map[city_2][city_1] = distance_Val;
    }
    
    
    // Vector with calculated minimum distance from source
    vector<int> distance(num_Cities, INT_MAX);
    
    // Vector to keep track of visited vertices source
    vector<bool> visited(num_Cities, false);
    
    // Source distance to itself is 0
    distance[source_Vertex] = 0;
    
    // Compute using Dijkstra's Algorithm
    for(int i = 0; i < num_Cities-1; i++) {
        // Extract min
        int u = get_Min_Dis(distance, visited);
        // Mark it as visited
        visited[u]= true;
        // Visit neighbors and update
        for(int v = 0; v < num_Cities; v++) {
          if(!visited[v] && // Not visited
             graph_Map[u][v] < distance[v] && // Edge exists
             distance[u]+graph_Map[u][v]<distance[v]) // Smaller edge
          {
              distance[v]=distance[u]+graph_Map[u][v];
          }
        }
    }
    
    // Print Min distance to destination
    cout << distance[destination_Vertex];
    return 0;
}
