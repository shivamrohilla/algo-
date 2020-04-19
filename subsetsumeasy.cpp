#include <iostream>
using namespace std;



bool subsetsumzero(int arr[],int si,int n,int curr,int len)
{


	if(si==n)
	{
		if(curr==0 and len>0)
		{
			return true;
		}
		return false;
	}

	bool  include=subsetsumzero( arr,si+1, n,curr+arr[si],len+1);
	bool  exclude=subsetsumzero(arr,si+1,n,curr,len);

	return (include or exclude);
}

int main(int argc, char const *argv[])
{
	
	int arr[]={1,3,2,2,5,6,-3};
	if(subsetsumzero(arr,0,7,0,0))
	{
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}





