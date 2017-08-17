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
/*
The optimal solution involves having only two variables to track whether the first row and column have a zero or not.
The while traversing the matrix to find zeros, you propagate the zero to first row and column.
So from 
   35    0    6   26   19   24
    3   32    0   21   23   25
   31    9    2   22   27   20
    8   28   33   17   0   15
   30    5   34   12   0   16
    4   36   29   13   0   11
You go to something like
   35    0    0   26   0   24
    3   32    0   21   23   25
   31    9    2   22   27   20
    0   28   33   17   0   15
    0    5   34   12   0   16
    0   36   29   13   0   11
Notice that the zeros have propagated to the first row and column.
Now again you go through the first row and column and set the required row or column to zero depending on whether you encounter a zero or not.
*/