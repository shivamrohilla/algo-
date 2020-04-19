#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


void sumitup(int s,int arr[],int n,vector<int> temp,int target,int ans){
	if(ans==target){

		for(int i=0;i<temp.size();i++){
			cout<<temp[i]<<" ";
		}
		cout<<endl;

		return;
	}
	if(ans>target){
		return;
	}

	for(int i=s;i<n;i++){
		if( i==s or arr[i] != arr[i-1] ){
		temp.push_back(arr[i]);
		sumitup(i+1,arr,n,temp,target,ans+arr[i]);
		temp.pop_back();
		}
	}



}




int main(int argc, char const *argv[])
{
	
	int arr[]={10 ,1, 2, 7, 6, 1, 5};

	sort(arr,arr+7);
	vector<int> temp;

	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}

	cout<<endl;
	// for(int i=0;i<6;i++)
	// {
	// 	if(arr[i]==arr[i+1])
	// 	{
	// 		arr[i]=0;
	// 	}
	// }

	sumitup(0,arr,7,temp,8,0);
	return 0;
}

