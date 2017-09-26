/*
Cracking the Coding Interview
Check Permutation
Question 1.2: Given two strings find if they are a permutation of the other
-----
Variants: 
-----
Hints/Good questions to ask: Ask for what a permutation means, don't assume something
A sort could work but it'd be of O(nlog(n)), if you were allowed some space you could do it in O(n)
Ask about character range, that would help with narrowing down the possiblilities (Unicode or ASCII)
Ask about character cases, whitespaces etc. If character case doesn't matter then first convert your input to lowercase. 
Iterate through the string and use (std::tolower(char) on each char.
Whitespaces don't matter because you can consider them to different characters by themselves.
But if they do, remove them from the string using yourString.erase in conjunction with yourString.remove.
-----
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isPermutation_Sort(string inputA, string inputB);
bool isPermutation_Count(const string &inputA, const string &inputB);
int main() {
    string inputA, inputB;
    cout<<"Enter the input strings: ";
    cin>>inputA>>inputB;
    int lenA = inputA.length();
    int lenB = inputB.length();
    if(lenA!=lenB){
        cout<<"The strings aren't permutations of each other"<<endl;
        return 0;
    }
    if(isPermutation_Count(inputA,inputB)){
        cout<<"The strings are permutations of each other"<<endl;
    } else {
        cout<<"The strings aren't permutations of each other"<<endl;
    }
    return 0;
}

bool isPermutation_Sort(string inputA, string inputB){
    sort(inputA.begin(),inputA.end());
    sort(inputB.begin(),inputB.end());
    for(int i=0;i<inputA.length();i++){
        if(inputA[i]!=inputB[i]){
            return false;
        }
    }
    return true;
}

bool isPermutation_Count(const string &inputA, const string &inputB){
    int characterCount[256] = {0};
    for(int i=0;i<inputA.length();i++){
        int value = int(inputA[i]);
        characterCount[value]++;
    }
    for(int i=0;i<inputB.length();i++){
        int value = int(inputB[i]);
        characterCount[value]--;
        if(characterCount[value]<0){
            return false;
        }
    }
    return true;
}