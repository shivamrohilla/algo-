#include<iostream>
using namespace std;



bool canvegive(int n,int m,int x, int y,int mid)
{


return mid*x<=m + (n-mid)*y;
}

int winningcbscholarship(int n,int m,int x, int y)
{
	int minstudents=0;
	int maxstudents=n;

	int ans;

	while(minstudents<=maxstudents)
	{
		int mid=minstudents+(maxstudents-minstudents)/2;

		if(canvegive(n, m, x,  y, mid))
		{
			ans=mid;
			minstudents=mid+1;
		}
		else
		{
			maxstudents=mid-1;
		}
	}
}


int main(int argc, char const *argv[])
{
	

	long n,m,x,y;
	cin>>n>>m>>x>>y;

	cout<<winningcbscholarship(n,m,x,y);
	return 0;
}