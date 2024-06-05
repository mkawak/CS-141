//
//  main.cpp
//  B. The simplest knapsack problem in the world
//
//  Created by Majd Kawak on 10/20/22.
//

#include <iostream>
#include <vector>

using namespace std;

// Compute 0-1 Knapsack
void compute_Knapsack(vector<vector<int>>& weight_value_Vec, vector<vector<int>>& matrix_To_Solve, int& row, int& column) {
    
    int max_Value = 0;
    // Go through rows of Matrix, starting at 1(first row always 0 with 0 item)
    for (int item = 1; item < row; item++) {
        
        // Go through columns of Matrix, starting at 1(first column always 0 with 0 weight capacity)
        for (int weight = 1; weight < column; weight++) {
            
            // Hold our potential best value
            int best_Value = 0;
            
            // Value of previuos row (if we can't add new item we pass it on)
            int pre_Value = matrix_To_Solve[item-1][weight];
        
            // Check if we can add current item to column
            if (weight - weight_value_Vec[item][0] >= 0) {
                
                // Get current item value
                int current_Item_Value = weight_value_Vec[item][1];
                
                // Get item with weight that is offset of current weight column backward 
                int pre_Item_Weight = matrix_To_Solve[item-1][weight - weight_value_Vec[item][0]];
                
                // Compute best value
                best_Value = current_Item_Value + pre_Item_Weight;
            }
            // Choose best of 2 solutions
            matrix_To_Solve[item][weight] = (best_Value > pre_Value)? best_Value : pre_Value;
            
            // Update MAX value
            max_Value = (matrix_To_Solve[item][weight] > max_Value)? matrix_To_Solve[item][weight] : max_Value;
        }
    }
    // Display MAX value
    cout << max_Value;
}

int main(int argc, const char * argv[]) {
    
    // Input weight / items number
    int knap_Weight;
    int num_Items;
    
    cin >> knap_Weight;
    cin >> num_Items;
    
    // Increase by 1 to offset Matrix 0/0
    knap_Weight++;
    num_Items++;
    
    // Input Weight / Value vector
    vector<vector<int>> weight_value_Vec(num_Items, vector<int>(2));
    int temp = 0;
    for(int i = 1; i < num_Items; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> temp;
            weight_value_Vec[i][j] = temp;
        }
    }
    
    // Initialize 2d vector "Matix" size, all '0'
    vector<vector<int>> knapsack_Matrix(num_Items,vector<int>(knap_Weight));

    // Compute Knapsack "Matrix"
    compute_Knapsack(weight_value_Vec,knapsack_Matrix,num_Items,knap_Weight);

    return 0;
}
