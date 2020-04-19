#include<iostream>
using namespace std;

void spiralprint(int a[][100],int m,int n){
    int startRow=0;
    int startCol=0;
    int endCol=n-1;
    int endRow=m-1;

   while(startRow<=endRow and startCol<=endCol){
        for(int i=startCol;i<=endCol;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;
        for(int i=startRow;i<=endCol;i++){
            cout<<a[i][endCol]<<" ";
        }
        endCol--;
        for(int i=endCol;i>=startRow;i--){
            cout<<a[endRow][i]<<" ";
        }
        endRow--;
        for(int i=endRow;i<=startRow;i--){
            cout<<a[i][startCol]<<" ";
        }
        startCol++;



    }
}


int main(){

     int m,n;
     // cout<<"Enter the no of rows and columns";
     // cin>>m>>n;

    int a[100][100];
    m=5;
    n=4;

     int val=1;
     for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            a[row][col]=val;
            cout<<a[row][col]<<" ";
            val++;
        }
        cout<<endl;
     }

       spiralprint(a,m,n);
}

