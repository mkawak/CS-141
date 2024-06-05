//
//  main.cpp
//  C. Wizard Chess
//
//  Created by Majd Kawak on 9/30/22.
//

#include <iostream>
#include <string>
using namespace std;

struct Tree {
    string val;
    Tree *option1, *option2, *option3, *option4, *option5, *option6, *option7, *option8;
};
void check21topright(int row, int col){
    if(row+2<=8&&col+1<='h'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21topleft(int row, int col){
    if(row+2<=8&&col-1>='a'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21downright(int row, int col){
    if(row-2>=1&&col+1<='h'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21downleft(int row, int col){
    if(row-2>=1&&col-1>='a'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21righttop(int row, int col){
    if(row+1<=8&&col+2<='h'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21rightdown(int row, int col){
    
    if(row+1>=1&&col-2>='a'){
        return true;
    }
    else{
        return false;
    }
}
void check21lefttop(int row, int col){
    if(row+1<=8&&col-2>='a'){
        return true;
    }
    else{
        return false;
    }
    
}
void check21leftdown(int row, int col){
    if(row-1>=1&&col-2>='a'){
        return true;
    }
    else{
        return false;
    }
    
}
void mapRoutes(Tree node){
    int row = node.val.at(1);
    char col = node.val.at(0);
    
    
}
int main(int argc, const char * argv[]) {
    
    int takenSqNum;
    cin >> takenSqNum;
    string takenSqVal[takenSqNum];
    for(int i = 0; i<takenSqNum; i++){
        cin >> takenSqVal[i];
    }
    string start;
    string dest;
    cin >> start;
    cin >> dest;
    Tree start;
    start.val=start;
    mapRoutes(start);
        
    
    
    return 0;
}
