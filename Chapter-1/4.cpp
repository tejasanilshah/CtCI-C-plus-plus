/*
Cracking the Coding Interview
Question 1.4: Permutation string == Palindrome?
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

bool canBePalindrome(const string& input);
int main() {
    string input;
    cout<<"Enter the input string: ";
    cin>>input;
    if( canBePalindrome(input) ){
        cout<<"The permutation of the input can be a palindrome"<<endl;
    } else {
        cout<<"No permutation of the input can be a palindrome"<<endl;
    }
    return 0;
}

bool canBePalindrome(const string& input){
    int asciiArray[255] = {0};
    bool hasOddOccurances = false;
    int length = input.length();
    for(int i=0;i<length;i++){
        asciiArray[ int(input[i]) ]++;
    }
    for(int i=0;i<255;i++){
        if(hasOddOccurances && asciiArray[i]%2!=0 ){
            return false;
        }
        if(asciiArray[i]%2!=0){
            hasOddOccurances = true;
        }
    }
    return true;
}
/*
PS: There is a more elegant and optimal solution to doing this. Use a bit vector instead of an int array to keep counts of the characters.
Everytime you encounter a character toggle the bit, that will essentially keep a track of even or odd. It the bit is one, that means there have been odd occurances,
and a zero means that there have been even occurances.
After going through the entire string check whther there is either exactly one bit set to 1, or no bits set to one.
*/