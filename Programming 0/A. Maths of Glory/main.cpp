//
//  main.cpp
//  A. Maths of Glory
//
//  Created by Majd Kawak on 9/29/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int jigsawNum1;
    int jigsawNum2;
    int roundNum;
    int num1;
    int num2;
    int num3;
    int num4;
    int team1;
    int team2;
    cin >> jigsawNum1;
    jigsawNum2 = jigsawNum1;
    cin >> roundNum;
    for(int i = 0; i < roundNum; i++){
        cin >> num1;
        cin >> num2;
        cin >> num3;
        cin >> num4;
        team1 = num1*num2;
        team2 = num3*num4;
        jigsawNum1 -= team1;
        jigsawNum2 -= team2;
        if(jigsawNum1<=0 && jigsawNum2 >0){
            cout << "Team 1 wins at round " << i+1 << "!" << endl;
            i = roundNum;
        }
        else if(jigsawNum1>0 && jigsawNum2 <=0){
            cout << "Team 2 wins at round " << i+1 << "!" << endl;
            i = roundNum;
        }
        else if(jigsawNum1<=0 && jigsawNum2 <=0){
            cout << "It's a tie at round " << i+1 << "!" << endl;
            i = roundNum;
        }
        else if(i == roundNum-1 && jigsawNum1>0 && jigsawNum2 >0){
            cout << "Oh no!" << endl;
        }
        
    }

    return 0;
}
