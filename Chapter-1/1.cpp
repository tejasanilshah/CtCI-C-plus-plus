/*
Cracking the Coding Interview
Question 1.1: Implement an algorithm to determine if a string has all unique characters.
-----
Variant: What if you cannot use additional data structures?
-----
Good questions to ask: What is the range of input characters? Depending on the input, the answer gets narrower or broader.
If it is ASCII then 128 characters, extended ASCII 256
You will simply initialize a boolean array of the same size and set the value to true the first time you encounter a character.
A good optimization is to compare the length of the input to the maximum unique characters in the character set. 
If the length is greater then there is no way that the string has all unique characters.
Another optimization is to use bitvectors instead of a boolean array. Decreases the space complexity by a factor of 8. 
But considering the fact that the maximum characters will be in the order of hundreds, the space that we save isn't a lot.
-----
*/
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
const int maxCharacters = 256;
bool isUnique_bruteforce(const string &input);
bool isUnique_booleanArray(const string &input);
bool isUnique_bitVector(const string &input);
int main()
{
    string input;
    cout << "Enter the input string: ";
    cin >> input;
    if (input.length() > maxCharacters)
    {
        cout << "Duplicate found in the string" << endl;
        return 0;
    }
    else
    {
        //Replace function as required
        bool found_duplicate = isUnique_bitVector(input);
        if (found_duplicate)
        {
            cout << "No duplicates in the string" << endl;
        }
        else
        {
            cout << "Duplicate found in the string" << endl;
        }
        return 0;
    }
}
bool isUnique_bruteforce(const string &input)
{
    int length = input.length();
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (input[i] == input[j])
            {
                cout << input[i] << " " << input[j] << endl;
                return false;
            }
        }
    }
    return true;
}

bool isUnique_booleanArray(const string &input)
{
    bool booleanArray[maxCharacters] = {0};
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (booleanArray[int(input[i])])
        {
            return false;
        }
        else
        {
            booleanArray[int(input[i])] = true;
        }
    }
    return true;
}

bool isUnique_bitVector(const string &input)
{
    bitset<maxCharacters> bits(0);
    for (int i = 0; i < input.length(); i++)
    {
        int intValue = input[i];
        if (bits.test(intValue))
        {
            return false;
        }
        else
        {
            bits.set(intValue);
        }
    }
    return true;
}
