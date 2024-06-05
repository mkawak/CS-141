//
//  main.cpp
//  C. Number Candles
//
//  Created by Majd Kawak on 10/10/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int max_Size = 0;
bool exit_Bool = false;

void find_Combo_Sum(vector<vector<int>> &multi_Combo, vector<int> &one_Combo, vector<int> &prices, int dollars, int index) {
    // If no dollars left return
    if (dollars < 0){
        return;
    }
    // No money Left \\if (dollars == 0)<-add if we cant buy items no more with left money
    if (dollars == 0||(dollars>0&&dollars<prices[index])){
        //Finish and add
        //Check bigest size combos (I only care about quantity)
        if(one_Combo.size()>=max_Size) {
            multi_Combo.push_back(one_Combo);
            if(max_Size==0){
                max_Size=(int)one_Combo.size();
            }
        }
        else{
            exit_Bool = true;
        }
        return;
    }
    while (index < prices.size() && dollars - prices[index] >= 0)
    {
        //Push price
        one_Combo.push_back(prices[index]);
        //Recersive Call
        find_Combo_Sum(multi_Combo, one_Combo, prices, dollars - prices[index], index);
        //Exit if next vector is smaller than max amount
        if(exit_Bool==false){
            //Move to next element
            index++;
            //Back track so I get different numbers in combos
            one_Combo.pop_back();
        }
        else{
            break;
        }
  }
}
void remove_Duplicates(vector<int>& prices){
    // To store unique Prices
    vector <int> no_Dup;
    // Making sure we dont add dupicates
    unordered_set <int> no_Dup_Set;
    sort(prices.begin(), prices.end());
    // Run throuth all elements of prices
    for(auto i : prices) {
        if(no_Dup_Set.find(i) == no_Dup_Set.end()) {
            no_Dup_Set.insert(i);
            no_Dup.push_back(i);
        }
    }
    prices = no_Dup;
    no_Dup_Set.clear();
    no_Dup.clear();
}

vector<vector<int>> find_Array_Combos(vector<int>& prices, int dollars) {
    remove_Duplicates(prices);
    // Vector of vectors of possible combos
    vector<vector<int>> multi_Combo;
    // Vector to store 1 unique combo
    vector<int> one_Combo;
    find_Combo_Sum(multi_Combo, one_Combo, prices, dollars, 0);
    return multi_Combo;
}
//This function is to find bigest candle index for price passed
int find_Candle(vector<pair<int, int>> &number_Prices, int &price){
    int temp = 0;
    int arr_Size = (int)number_Prices.size();
    for(int k = 0; k < arr_Size; k++){
        if(price==number_Prices.at(k).first){
            temp = number_Prices.at(k).second;
            break;
        }
    }
    return temp;
}
string sort_Candles(vector <int> &candles) {
    string max_Num;
    //Sort candles first
    sort(candles.begin(), candles.end());
    
    //Combine them into one string
    for(int m= (int)candles.size()-1; m >=0 ; m--) {
        max_Num = max_Num +to_string(candles.at(m));
    }
    
    //Clear array for next combo
    candles.clear();
    return max_Num;
}

int main(int argc, const char * argv[]) {
    int dollars;
    while(cin >> dollars){
        if(!cin){
            break;;
        }
        int candle_Size = 9;
        vector<pair<int, int>> number_Prices;
        int value;
        for(int i = 0; i<candle_Size;i++){
            cin >> value;
            number_Prices.push_back({value,i+1});
        }
        // Just for prices
        vector<int> prices_Arr;
        for(int i = 0; i<candle_Size;i++){
            prices_Arr.push_back(number_Prices.at(i).first);
        }
        
        //Find all combos
        vector<vector<int>> all_Combos_Vec = find_Array_Combos(prices_Arr, dollars);
        
        //Check for empty
        if (!all_Combos_Vec.empty()) {
            //Sort based on second element
            sort(number_Prices.begin(),number_Prices.end(), [](auto &left, auto &right) {
                return left.second > right.second;
            });
            //Add candles at each combo separately
            vector <int> temp_Candles;
            //Store each combo and combine
            vector <string> number_Max;
            
            //Run through big combos and combine numbers
            for (int i = 0; i < all_Combos_Vec.size(); i++){
                if (!all_Combos_Vec[i].empty()&&all_Combos_Vec[i].size()==max_Size){
                    for (int j = 0; j < all_Combos_Vec[i].size(); j++){
                        int price = all_Combos_Vec[i][j];
                        temp_Candles.push_back(find_Candle(number_Prices, price));
                    }
                    //Sort order candles to shape bigest number
                    number_Max.push_back(sort_Candles(temp_Candles));
                }
            }
            //Get max number out of candles
            sort(number_Max.begin(), number_Max.end());
            int last_Element = (int)number_Max.size();
            cout << number_Max[last_Element - 1] << endl;
        }
        cout << "Maximum number = " << max_Size << endl;
        max_Size = 0;
        exit_Bool = false;
    }
  return 0;
}
