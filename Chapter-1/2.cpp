/*
Cracking the Coding Interview
Question 1.2: Given two strings find if they are a permutation of the other
-----
Variants: 
-----
Hints: Ask for what a permutation means, don't assume something
A sort could work but it'd be of O(nlog(n)), if you were allowed some space you could do it in O(n)
Ask about character range, that would help with narrowing down the possiblilities (Unicode or ASCII)
-----
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string inputA, inputB;
    cout<<"Enter the input strings: ";
    cin>>inputA>>inputB;
    int characterCount[255] = {0};
    int lenA = inputA.length();
    int lenB = inputB.length();
    if(lenA!=lenB){
        cout<<"The strings aren't permutations"<<endl;
        return 0;
    }
    for(int i=0;i<lenA;i++){
        characterCount[int(inputA[i])]++;
    }
    for(int i=0;i<lenB;i++){
        characterCount[int(inputB[i])]--;
    }
    for(int i=0;i<255;i++){
        if(characterCount[i]!=0){
            cout<<"The strings aren't permutations"<<endl;
            return 0;
        }
    }
    cout<<"The strings are permutations"<<endl;
    return 0;
}
/*
Missing things | Optimizations: 
Think about character cases, or whitespaces
*/