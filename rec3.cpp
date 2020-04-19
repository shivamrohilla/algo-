#include<iostream>
#include<math.h>
using namespace std;

int noOfways(int n)
{
	if(n==1)
	{
		return 0;
	}
	int minusone=noOfways(n-1);
	int bytwo=n;
	int bythree=n;
	if(n%2==0)
	{
		bytwo=noOfways(n/2);
	}
	if(n%3==0)
	{
		bythree=noOfways(n/3);
	}
	return min(minusone,min(bythree,bytwo))+1;

}
/*string code[]={" ",".","abc","def","ghi"};
void printkeypad(string str,string ans)
{
	if(str.length()){
		cout<<ans<<endl;
		return;
	}

	printkeypad(str.substr(1),ans+code[atoi(str[0])][1]);
	printkeypad(str.substr(1),ans+code[atoi(str[0])][1]);
	printkeypad(str.substr(1),ans+code[atoi(str[0])][1]);

}*/

/*int perfectsq(int n)
{
	int i=n;
	for(i=1;i<=n;i++)
	{
		if()
	}
}*/

int improvespower(int n,int p)
{
	if(p==0)
	{
		return 1;vv
	}
	int ans;
	if(p%2==0)
	{
		 ans=improvespower(n,p/2);
		return ans*ans;
	}
	if(p%2==1)
	{
		ans=improvespower(n,p/2);
		return ans*ans*n;
	}
}
void (string str,string ans)
{
	if(str.length()==0)
	{

	}

	char ch=str[0];
	string res=str.substr(1);

	printpairs(res,ans+ch);
	printpairs(res,ans)
}
int main(int argc, char const *argv[])
{
	
	//cout<<noOfways(10);
	//printkeypad("123","");
	cout<<improvespower(2,8);
	
	return 0;
}