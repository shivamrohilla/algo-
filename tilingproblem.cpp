#include<iostream>
using namespace std;

int tiling2(int n,int m,int l)
{
	if(n==0 and m==0)
	{
		return 1;
	}

	if(n<0 or m<0)
	{
		return 0;
	}

	int horizontal=tiling2(n-1,m-l,l);
	int vertical=tiling2(n-m,m-1,l);


	return horizontal+vertical;
}
int main(int argc, char const *argv[])
{
	
	cout<<tiling2(4,16,4);
	return 0;
}