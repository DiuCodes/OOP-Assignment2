
#include <iostream>
#include <vector>

using namespace std;

struct Domino{
    int leftDots;
    int rightDots;
};

//Function to check if it's possible to make a chain of dominos
bool FormsDominoChain(vector<Domino> &dominos, vector<Domino> &chain){
    if (chain.size() < dominos.size() || chain.size() > dominos.size()){
        return false;
    } else {
        return true;
    }
}

int main(){

    vector<Domino>dominos = { {1, 4}, {2, 6}, {4, 4}, {6, 1}, {4, 3} };
    vector<Domino>matched;
    vector<Domino>chain;
    
    //Loop through dominos, if they match then append them to matched list
    int mc = -1;
    for (int i=0; i<dominos.size(); i++){
        for (int j=0; j<dominos.size(); j++){
            if (mc != -1){ //Skip if at the first loop
                if (dominos[i].rightDots == dominos[j].leftDots && matched[mc].rightDots == dominos[i].leftDots){ //Check if the leftDots and rightDots match
                    //If leftDots and rightDots match, then append to matched list
                    matched.push_back(dominos[i]);
                    matched.push_back(dominos[j]);
                    mc += 2;
                }
            } else { //First loop
                if (dominos[i].rightDots == dominos[j].leftDots){
                    //If leftDots and rightDots match, then append to matched list
                    matched.push_back(dominos[i]);
                    matched.push_back(dominos[j]);
                    mc += 2;
                }
            }
        }
    }

    //Check any matches from the left side of the vector
    for (int i=dominos.size(); i>=0; i--){
        if (dominos[i].rightDots == matched[0].leftDots){
            matched.insert(matched.begin(), dominos[i]);
        }
    }

    //Check and filter out duplicates
    for (int i=0; i<matched.size(); i++){
        if (matched[i].leftDots == matched[i+1].leftDots && matched[i].rightDots == matched[i+1].rightDots){
            continue;
        } else {
            chain.push_back(matched[i]);
        }
    }

    if (FormsDominoChain(dominos, chain)){ //Check if possible to make a chain, if possible then print the chain
        for (int i=0; i<chain.size(); i++){
            if (i == 0){
                cout<<chain[i].leftDots<<'|'<<chain[i].rightDots;
            } else {
                cout<<"  -  "<<chain[i].leftDots<<'|'<<chain[i].rightDots;
            }
        }
    } else { //If it's not possible to make a chain, then print this message
        cout << "Can not form a chain from the given Dominoes!" ;
    }

    return 0;
}