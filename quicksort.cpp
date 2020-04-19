#include <iostream>
using namespace std;

void quicksort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return;
	}

	int mid=start + (end- start)/2;
	int pivot=arr[mid];

	int left=start;
	int right=end;

	while(left<=right)
	{
		while(arr[left]<pivot)
		{
			left++;
		}

		while(arr[right]>pivot)
		{
			right--;
		}

		if(left<=right)
		{
			swap(arr[left],arr[right]);
			left++;
			right--;
		}


	}

	quicksort(arr,start,right);
	quicksort(arr,left,end);


}

int main(int argc, char const *argv[])
{
	
	int arr[]={5,8,3,1,7,0,3,6};
	quicksort(arr,0,7);


	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}