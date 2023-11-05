
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string word, alt;
    ifstream in("post.txt"); //Input file stream object to read from 'post.txt'
    ofstream out("altered.txt"); //Output file stream object to write to 'altered.txt'
    ifstream alter("alternatives.txt"); //Input file stream object to read from 'alternatives.txt'

    //Reading from 'post.txt' word by word and checking if the word is a censored word,
    // if it's then replace it with its alternative in 'alternatives.txt' then append to 'altered.txt',
    // else if the word ain't a censored word then also append it to 'altered.txt' respectively
    while(in >> word){
        if (word == "must"){ 
            while(alter >> alt){
                if (alt == "may"){
                    out<<alt+" ";
                    break;
                }
            }
        } else if (word == "bad"){
            while(alter >> alt){
                if (alt == "good"){
                    out<<alt+" ";
                    break;
                }
            }
        } else if (word == "stubborn"){
            while(alter >> alt){
                if (alt == "humble"){
                    out<<alt+" ";
                    break;
                }
            }
        } else if (word == "hate"){
            while(alter >> alt){
                if (alt == "love"){
                    out<<alt+" ";
                    break;
                }
            }
        } else if (word == "rude"){
            while(alter >> alt){
                if (alt == "polite"){
                    out<<alt+" ";
                    break;
                }
            }
        } else if (word == "reject"){
            while(alter >> alt){
                if (alt == "accept"){
                    out<<alt+" ";
                    break;
                }
            }
        } else { //If the word ain't a censored word then also append it to 'altered.txt' respectively
            out<<word+" ";
        }
    }
    cout<<"\nSuccessfully altered the post!\nOpen 'altered.txt' file to see the altered content.\n\n";
    return 0;
}