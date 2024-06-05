//
//  main.cpp
//  C. A slightly more complicated knapsack problem
//
//  Created by Majd Kawak on 10/20/22.
//

#include <iostream>
#include <vector>

using namespace std;

// Compute Knapsack
void compute_Knapsack(vector<vector<int>>& weight_value_Vec, vector<vector<int>>& matrix_To_Solve, int& row, int& column, int& k_Items) {
    
    // Max Value
    int max_Value = 0;
    
    // Go through rows of Matrix, starting at 1(first row always 0 with 0 item)
    for (int item = 1; item < row; item++) {
        
        // Go through columns of Matrix, starting at 1(first column always 0 with 0 weight capacity)
        for (int weight = 1; weight < column; weight++) {
            
            // Hold our potential best value
            int best_Value = 0;
            
            // Hold best solution for repeated items
            int best_Solution = 0;
            
            // Value of previuos row (if we can't add new item we pass it on)
            int pre_Value = matrix_To_Solve[item-1][weight];
            
            // Check if we reached k items allowed
            bool k_Items_Reached = false;
            
            // Check if we can't fit more items
            bool exit_Bool = false;
            
            // Current k items chosen
            int k_Items_Taken = 0;
            
            while (!k_Items_Reached && k_Items_Taken < k_Items && !exit_Bool) {
                
                // Check if we can add current item to column
                if (weight - (k_Items_Taken+1) * weight_value_Vec[item][0] >= 0) {
                    
                    // Get current item value
                    int current_Item_Value = (k_Items_Taken+1) * weight_value_Vec[item][1];
                    
                    // Get item with weight that is offset of current weight column backward
                    int pre_Item_Weight = matrix_To_Solve[item-1][weight - (k_Items_Taken+1) * weight_value_Vec[item][0]];
                    
                    // Compute best value
                    best_Value = current_Item_Value + pre_Item_Weight;
                    
                    // Check if we have better solution
                    best_Solution = (best_Value > best_Solution)? best_Value: best_Solution;
                    
                    // Increase items taken
                    k_Items_Taken++;
                }
                else {
                    // Exit if we can't fit more items
                    exit_Bool = true;
                }
            }
            // Choose best of 2 solutions
            matrix_To_Solve[item][weight] = (best_Solution > pre_Value)? best_Solution : pre_Value;
            
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
    int k_items;
    
    cin >> knap_Weight;
    cin >> num_Items;
    cin >> k_items;
    
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
    compute_Knapsack(weight_value_Vec,knapsack_Matrix,num_Items,knap_Weight, k_items);

    return 0;
}
