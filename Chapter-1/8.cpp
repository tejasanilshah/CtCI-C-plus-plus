/*
Cracking the Coding Interview
Question 1.8: Zero Matrix
Write an algorithm such that if an element in an MxN matrix is 0, it's entire row and column are set to 0
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
    int m,n;
    cout<<"Input the size of the matrix M, N: ";
    cin>>m>>n;
    int matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    bool isZero[m+n];
    for(int i=0;i<m+n;i++){
        isZero[i]=false;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                isZero[i]=true;
                isZero[m+j]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(isZero[i]==true){
            //Set the row to zero
            for(int k=0;k<n;k++){
                matrix[i][k]=0;
            }
        }
    }    
    for(int j=0;j<n;j++){
        if(isZero[m+j]==true){
            //Set column to zero
            for(int k=0;k<n;k++){
                matrix[k][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
