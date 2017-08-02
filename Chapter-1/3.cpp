/*
Cracking the Coding Interview
Question 1.3: URLify a string.
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
int MAX_SIZE = 100;
using namespace std;
int main() {
    char input[MAX_SIZE];
    int trueLength;
    cout<<"Input the string to URLify and true length:"<<endl;
    cin>>input;
    cout<<"Input the true length: "<<endl;
    cin>>trueLength;
    // for(int i=trueLength-1;i>=0;i++){
    //     cout<<input[i]<<endl;
    // }
    return 0;
}
/*
Solution outline
Start from the end of the string, copy over each character to the true end of the string.
When you encounter a space, copy %20 instead and move to the next character.
Need to look up the syntax to do this in C++.
*/