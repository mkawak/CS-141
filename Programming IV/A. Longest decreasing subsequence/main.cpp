//
//  main.cpp
//  A. Longest decreasing subsequence
//
//  Created by Majd Kawak on 11/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int compute_LDS(int arr[], int arr_Size) {
    
    // Longest sequance value number
    int max = 0;
    
    // Initialize all value vector to 1
    vector<int> lds_At_Index(arr_Size, 1);

    // Compute LDS at index
    for (int i = 1; i < arr_Size; i++) {
        for(int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && lds_At_Index[i] < lds_At_Index[j] + 1) {
                lds_At_Index[i] = lds_At_Index[j] + 1;
                max = (max < lds_At_Index[i])? lds_At_Index[i] : max;
            }
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    // Input Array
    int arr_Size;
    cin >> arr_Size;
    int arr[arr_Size];
    for (int i = 0; i < arr_Size; i++){
        cin >> arr[i];
    }
    
    // Compute LDS
    cout << compute_LDS(arr, arr_Size) << endl;
    
    return 0;
}
