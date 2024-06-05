//
//  main.cpp
//  B. Weighted Edit Distance
//
//  Created by Majd Kawak on 11/05/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void compute_DP(vector<int> &arr_A, vector<int> &arr_B, int a_Size, int b_Size, vector<vector<int>> &dp) {
    //Compute using recursion from slides
    for (int a_index = 0; a_index < a_Size; a_index++){
        for (int b_index = 0; b_index < b_Size; b_index++){
            //------------------------------------------
            // Case 0: If i=0 or j=0
            if(a_index==0 && b_index == 0) {
                // Update table, Offseted element from main
                dp[a_index][b_index] = 0;
            }
            //------------------------------------------
            // Fill up firt row and first column to form
            // a string with value .+..+...+dp[0][j]
            else if( a_index == 0 && b_index > 0) {
                dp[a_index][b_index] = dp[0][b_index-1] + arr_B[b_index-1];
            }
            // or string with value .+..+...+dp[i][0]
            else if( a_index > 0 && b_index == 0) {
                dp[a_index][b_index] = dp[a_index-1][0] + arr_A[a_index-1];
            }
            //------------------------------------------
            // Case 1: If A[x] == B[x]
            else if (a_index > 0 && b_index >0 && arr_A[a_index-1] == arr_B[b_index-1]) {
                // Update table
                dp[a_index][b_index] = dp[a_index-1][b_index-1];
            }
            //------------------------------------------
            // Case 2: If A[x] != B[x]
            else {
                
                // Cost of Inserting
                int insert_Cost = dp[a_index][b_index-1] + arr_B[b_index-1];
                
                // Cost of Deleting
                int delete_Cost = dp[a_index-1][b_index] + arr_A[a_index-1];
                
                // Cost of Editing
                // Abs in case we get negative value from subtraction
                int edit_Cost = dp[a_index-1][b_index-1] + abs(arr_A[a_index-1]-arr_B[b_index-1]);
                
                // Update table, min of 3 solutions
                dp[a_index][b_index] = min(insert_Cost,min(delete_Cost,edit_Cost));
            }
            //------------------------------------------
        }
    }
}

int main(int argc, const char * argv[]) {
    
    // A and B
    vector <int> arr_A,arr_B;
    
    // Input A and B Size
    int a_size, b_size;
    cin >> a_size;
    cin >> b_size;

    // Set vector size
    arr_A.reserve(a_size);
    arr_B.reserve(b_size);
    
    // Input A
    for (int i = 0; i < a_size; i++) {
        cin >> arr_A[i];
    }
    // Input B
    for (int i = 0; i < b_size; i++) {
        cin >> arr_B[i];
    }
    
    // Solution Matrix, offsetting [0][0] element by 1
    vector<vector<int>>  dp(++a_size, vector<int>(++b_size));
    
    // Solve solution table
    compute_DP(arr_A, arr_B, a_size, b_size, dp);

    // Display last element
    cout << dp[a_size-1][b_size-1];
    
    return 0;
}
