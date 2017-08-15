/*
Cracking the Coding Interview
Question 1.6: String Compression
Implement a method to perform basic string compression using the counts of repeated characters
-----
Variants:
-----
Hints:
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
    string input;
    string compressedString;
    char currentChar;
    int count;
    cout<<"Enter the string input: ";
    cin>>input;
    int length = input.length();
    for(int i=0;i<length-1;i++){
        currentChar = input[i];
        count=1;
        while(currentChar==input[i+1]){
            count++;
            i++;
        }
        compressedString += currentChar;
        compressedString.append(to_string(count));
    }
    cout<<"The result is: ";
    if(compressedString.length() >= input.length()){
        cout<<input;
    } else {
        cout<<compressedString;
    }
    cout<<endl;
    return 0;
}
