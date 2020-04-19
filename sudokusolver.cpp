#include<iostream>
using namespace std;


bool isSafe(int sudoku[9][9],int row, int col, int n, int num)

{

	for(int i=0;i<n;i++)
	{
		if(sudoku[row][i]==num or sudoku[i][col]==num)
		{
			return false;
		}
	}

	int starting_r=(row/3)*3;
	int starting_c=(col/3)*3;

	for(int i=starting_r;i<starting_r+3;i++)
	{
		for(int j=starting_c;j<starting_c+3;j++)
		{
			if(sudoku[i][j]==num)
			{
				return false;
			}
		}
	}

	return true;
}



bool sudokusolver(int sudoku[9][9],int row, int col,int n)
{

	if(row==n)
	{
		for(int i=0;i<n;i++)
		{

			for(int j=0;j<n;j++)
			{
				cout<<sudoku[i][j]<<" ";
			}
			cout<<endl;
		}


		return true;
	}



	if(col==n)
	{
		return sudokusolver(sudoku,row+1,0,n);
	}

	if(sudoku[row][col]!=0)
	{
		return sudokusolver(sudoku,row,col+1,n);
	}




	for(int i=1; i<=9;i++)
	{
		if(isSafe(sudoku,row,col,n,i))
		{
			sudoku[row][col]=i;

			bool bachahuasudoku= sudokusolver(sudoku,row,col+1,n);

			if(bachahuasudoku)
			{
				return true;
			}
		}
	}

	sudoku[row][col]=0;

	return false;
}
int main(int argc, char const *argv[])
{
	
	int sudoku[9][9]={
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };


    sudokusolver(sudoku,0,0,9);
	return 0;
}