/*
Cracking the Coding Interview
Question 1.1: Implement an algorithm to determine if a string has all unique characters.
-----
Variant: What if you cannot use additional data structures?
-----
Good questions to ask: What is the range of input characters? Depending on the input, the answer gets narrower or broader.
If it is ASCII then 128 characters, extended ASCII 256
You will simply initialize a boolean array of the same size and set the value to true the first time you encounter a character.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//BB = Br
bool findDuplicateBF(const string& input);
bool findDuplicateASCII(const string& input);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    cout<<"Enter the input string: ";
    cin>>input;
    //Replace function as required
    bool foundDuplicate = findDuplicateASCII(input);
    if(foundDuplicate){
        cout<<"Duplicate found"<<endl;
    } else {
        cout<<"No duplicates in the string"<<endl;
    }
    return 0;
}
bool findDuplicateBF(const string& input){
    int length = input.length();
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(input[i]==input[j]){
                cout<<input[i]<<" "<<input[j]<<endl;
                return true;
            }
        }
    }
    return false;
}

bool findDuplicateASCII(const string& input){
    bool asciiArray[256] = {0};
    int length = input.length();
    for(int i=0;i<length;i++){
        if(asciiArray[int(input[i])]){
            return true;
            } else {
            asciiArray[int(input[i])]=true;
            }
    }
    return false;
}
