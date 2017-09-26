/*
Cracking the Coding Interview
Question 1.3: URLify a string.
-----
Variants:
-----
Hints/Good questions to ask: Does it have to be in place? 
If it doesn't need to happen in place, then it is pretty straight-forward.
Simply iterate over the string copying character by character and when you encounter a " " insert a "%20" instead.
With C++ because of a powerful standard library you can cheat a little by using the erase and insert functionality of the string library.
That kind of makes the question moot. So you should assume it is a question of arrays, and you've to move things around manually.
//TODO: Do it the char array way
-----
*/
#include <iostream>
#include <string>
using namespace std;
const string URLifiedSpace = "%20";
string URLify_STL(string input);
int main()
{
    string input;
    cout << "Input the string you want to URLify: ";
    getline(cin, input);
    //STL Method
    input = URLify_STL(input);
    cout << "The URLified string is: " << input << endl;
    return 0;
}
string URLify_STL(string input){
    int i = 0;
    while (i != input.size())
    {
        if (input[i] == ' ')
        {
            input.erase(i,1);
            input.insert(i, URLifiedSpace);
            i += 2;
        }
        i++;
    }
    return input;
}
/*
Solution outline
Start from the end of the string, copy over each character to the true end of the string.
When you encounter a space, copy %20 instead and move to the next character.
Need to look up the syntax to do this in C++.
*/