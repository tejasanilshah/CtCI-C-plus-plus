/*
Cracking the Coding Interview
Question 1.1: Implement an algorithm to determine if a string has all unique characters.
-----
Variant: What if you cannot use additional data structures?
-----
Good questions to ask: What is the range of input characters? Depending on the input, the answer gets narrower or broader.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    cout<<"Enter the input string: ";
    cin>>input;
    int length = input.length();
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(input[i]==input[j]){
                cout<<"Duplicate found"<<endl;
                return 0;
            }
        }
    }
    cout<<"No duplicates in the string"<<endl;
    return 0;
}
