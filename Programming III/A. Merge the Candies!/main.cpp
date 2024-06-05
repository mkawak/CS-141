//
//  main.cpp
//  A. Merge the Candies!
//
//  Created by Majd Kawak on 10/19/22.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long> &vec, int start, int mid, int end) {

    int left_Vec_Size = mid - start + 1;
    int right_Vec_Size = end - mid;
 
    // Alocate vectors
    vector<long> left_Vec;
    left_Vec.reserve(left_Vec_Size);
    vector<long> right_Vec;
    right_Vec.reserve(right_Vec_Size);
 
    // Copy to left and right
    for (int i = 0; i < left_Vec_Size; i++){
        left_Vec.push_back(vec.at(start + i));
    }
    for (int j = 0; j < right_Vec_Size; j++){
        right_Vec.push_back(vec.at(mid + 1 + j));
    }
 
    // Keep track of compared indecies
    int index_Left_Vec = 0;
    int index_Right_Vec = 0;
    int index_Merge_Vec = start;
    
    // Sort in descending order
    while (index_Left_Vec < left_Vec_Size && index_Right_Vec < right_Vec_Size) {
        if (left_Vec.at(index_Left_Vec) >= right_Vec.at(index_Right_Vec)) {
            vec.at(index_Merge_Vec) = left_Vec.at(index_Left_Vec);
            index_Left_Vec++;
        }
        else {
            vec.at(index_Merge_Vec) = right_Vec.at(index_Right_Vec);
            index_Right_Vec++;
        }
        index_Merge_Vec++;
    }
    
    //Check for leftovers
    while (index_Left_Vec < left_Vec_Size) {
        vec.at(index_Merge_Vec) = left_Vec.at(index_Left_Vec);
        index_Left_Vec++;
        index_Merge_Vec++;
    }
    while (index_Right_Vec < right_Vec_Size) {
        vec.at(index_Merge_Vec) = right_Vec.at(index_Right_Vec);
        index_Right_Vec++;
        index_Merge_Vec++;
    }

}
void merge_Sort(vector<long> &vec, int start, int end){
    if (start >= end) {
            return;
    }
    int mid = start + (end - start) / 2;
    merge_Sort(vec, start, mid);
    merge_Sort(vec, mid + 1, end);
    merge(vec, start, mid, end);
}

int main(int argc, const char * argv[]) {
    
    // Bags of candies
    vector<long> candy_Bags;
    // How many time Yihan needs to count
    long candies_Counted = 0;
    // Bags
    int bags;
    cin >> bags;
    // Change to Bags size
    candy_Bags.reserve(bags);
    // Input each bag number of candies
    for (int i = 0; i < bags; i++){
        long temp;
        cin >> temp;
        candy_Bags.push_back(temp);
    }

    // Count candies till empty
    
    do{
        // Sort in descending order
        merge_Sort(candy_Bags, 0, candy_Bags.size() - 1);

        // remove 2 smallest bags
        long Last_Two_Bags = candy_Bags.back();
        candy_Bags.pop_back();

        Last_Two_Bags += candy_Bags.back();
        candy_Bags.pop_back();
        
        // Add last 2 bags to count
        candies_Counted += 2 * Last_Two_Bags;

        // Insert merged bag into Bags
        candy_Bags.push_back(Last_Two_Bags);

    }while (candy_Bags.size() > 1);
    // Display number
    cout << candies_Counted;

    return 0;
}
