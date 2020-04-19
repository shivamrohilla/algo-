#include <iostream>
using namespace std;

void towerofhanoi(int n,char source,char dest,char helper)
{
	if(n==0)
	{
		return;
	}

	towerofhanoi(n-1,source,helper,dest);
	cout<<"Moving Ring "<<n<<" from "<<source<<" to "<<dest<<endl;;

	towerofhanoi(n-1,helper,dest,source);




}

int main(int argc, char const *argv[])
{
	
	towerofhanoi(4,'A','B','C');
	return 0;
}

