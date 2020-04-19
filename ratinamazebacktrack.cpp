#include<iostream>
using namespace std;

// void ratinamazepath(char maze[][4],int sr,int sc,int er,int ec,int sol[][10])
// {

// 	if(sr==er and sc==ec)
// 	{
// 		sol[sr][sc]=1;
// 		for(int i=0;i<=er;i++)
// 		{
// 			for(int j=0;j<=ec;j++)
// 			{
// 				cout<<sol[i][j];
// 			}
// 			cout<<endl;
// 		}
		
// 		cout<<endl;
// 		return;
// 	}
// 	if(sol[er][ec]==1)
// 	{
// 		return;
// 	}
// 	if(sr>er or sc>ec)
// 	{
// 		return;
// 	}
// 	if(maze[sr][sc]=='X')
// 	{
// 		return;
// 	}

// 	sol[sr][sc]=1;
// 	ratinamazepath(maze,sr,sc+1,er,ec,sol);
// 	ratinamazepath(maze,sr+1,sc,er,ec,sol);
// 	sol[sr][sc]=0;
// }






#include<iostream>
using namespace std;
int visited[100][100]={0};
bool ratinamazepath(char maze[4][4],int sr,int sc,int er,int ec,int sol[][10])
{

	if(sr==er and sc==ec)
	{
		
		sol[sr][sc]=1;
		for(int i=0;i<=er;i++)
		{
			for(int j=0;j<=ec;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		
		return true;
	}
	if(sol[er][ec]==1)
	{
		return true;
	}

	// if(visited[sr][sc]==1)
	// {
	// 	return false;
	// }
	if(sr>er or sc>ec)
	{
		return false;
	}
	if(maze[sr][sc]=='X')
	{
		return false;
	}
	

	sol[sr][sc]=1;
	visited[sr][sc]=1;
	bool left=false;
	bool up=false;
	
	bool horizontal=ratinamazepath(maze,sr,sc+1,er,ec,sol);
	bool vertical=ratinamazepath(maze,sr+1,sc,er,ec,sol);
	 if(visited[sr-1][sc]==0)
	 {
	 	 up=ratinamazepath(maze,sr-1,sc,er,ec,sol);
	 }
	 if(visited[sr][sc-1]==0)
	 {

		 left=ratinamazepath(maze,sr,sc-1,er,ec,sol);
	 }


	sol[sr][sc]=0;
	if(horizontal or vertical or left or up )
	{
		return true;
	}
	else
	{
		return false;
	}
}





int main(int argc, char const *argv[])
{
	
	char maze[4][4] = {
		{'0','0','0','0'},
		{'0','0','X','X'},
		{'0','0','0','0'},
		{'0','X','0','0'},
	};

	int sol[10][10]={0};
	ratinamazepath(maze,0,0,3,3,sol);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<visited[i][j];
		}
		cout<<endl;
	}
	return 0;
}