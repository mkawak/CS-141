//
//  main.cpp
//  B. Sorting Hat
//
//  Created by Majd Kawak on 9/30/22.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<string> gryffindorHouse;
    vector<string> hufflepuffHouse;
    vector<string> ravenclawHouse;
    vector<string> slytherinHouse;
    int studentNum;
    string studentName;
    string studentHouse;
    
    cin >> studentNum;
    for(int i = 0; i < studentNum; i++){
        cin >> studentName;
        cin >> studentHouse;

        if(studentHouse[0] == 'G'){
            gryffindorHouse.push_back(studentName);
        }
        else if(studentHouse[0] == 'H'){
            hufflepuffHouse.push_back(studentName);
        }
        else if(studentHouse[0] == 'R'){
            ravenclawHouse.push_back(studentName);
        }
        else if(studentHouse[0] == 'S'){
            slytherinHouse.push_back(studentName);
        }
        
    }
    sort(gryffindorHouse.begin(), gryffindorHouse.end());
    sort(hufflepuffHouse.begin(), hufflepuffHouse.end());
    sort(ravenclawHouse.begin(), ravenclawHouse.end());
    sort(slytherinHouse.begin(), slytherinHouse.end());
    cout << "Gryffindor" << endl;
    for(string i : gryffindorHouse){
        cout << i << endl;}
    cout << "Hufflepuff" << endl;
    for(string i : hufflepuffHouse){
        cout << i << endl;}
    cout << "Ravenclaw" << endl;
    for(string i : ravenclawHouse){
        cout << i << endl;}
    cout << "Slytherin" << endl;
    for(string i : slytherinHouse){
        cout << i << endl;}
    return 0;
}
