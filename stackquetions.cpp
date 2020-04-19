#include <iostream>
#include<stack>
#include<climits>

using namespace std;

bool balancedparanthesis(string str)
{

	stack<char> s;

	for(int i=0;i<str.length();i++){

		if(str[i]=='('){

			s.push(str[i]);
		}
		else{


			if(s.empty()){
				return false;
			}
			s.pop();
		}
	}

	return s.empty();


}

bool duplicate(string str){


	stack<char> s;

	for(int i=0;i<str.length();i++){

		if(str[i]==')'){

			if(s.top()=='('){
				return true;
			}

			else{

				while(s.top() != '('){

					s.pop();
				}

			}

			s.pop();

		}

		else{

			s.push(str[i]);
		}
	}

	return false;




}

void nextgraeterelemntsequencewiseprint(int arr[], int n){


	stack<int> s;
	int ans[n];
	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>arr[s.top()]){
			ans[s.top()]=arr[i];
			s.pop();

		}

		s.push(i);
	}

	while(!s.empty()){
			ans[s.top()]=-1;
			s.pop();

		}


	for(int i=0;i<n;i++){

		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

void nextsmallerelemntsequencewiseprint(int arr[], int n){


	stack<int> s;
	int ans[n];
	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]<arr[s.top()]){
			ans[s.top()]=arr[i];
			s.pop();

		}

		s.push(i);
	}

	while(!s.empty()){
			ans[s.top()]=-1;
			s.pop();

		}


	for(int i=0;i<n;i++){

		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

void nextGreater(int arr[], int n) {

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and s.top() < arr[i]) {
			int temp = s.top();
			s.pop();

			cout << temp << "->" << arr[i] << endl;
		}

		s.push(arr[i]);
	}

	while (!s.empty()) {
		int temp = s.top();
		s.pop();

		cout << temp << "->" << -1 << endl;
	}
}


void stockspan(int arr[],int n){

	stack<int> s;
	int ans[n];
	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>=arr[s.top()]){

			s.pop();

		}

		if(s.empty()){
			ans[i]=i+1;

		}

		else{
			ans[i]=i-s.top();

		}

		s.push(i);
	}
	for(int i=0;i<n;i++){

		cout<<ans[i]<<" ";
	}
	cout<<endl;
}


int histogram(int arr[],int n){


	stack<int> s;

	int maxArea=INT_MIN;

	int i=0;

	while(i<n){

		if(s.empty() or arr[i]>=arr[s.top()]){

			s.push(i);
			i++;
		}
		else{

			int height=arr[s.top()];
			s.pop();

			if(s.empty()){

				int width=i;
				maxArea=max(maxArea,width*height);
			}

			else{

				int width=(i-s.top())-1;

				maxArea=max(maxArea,width*height);

			}

		}

	}



	while(!s.empty()){


			
			int height=arr[s.top()];
			s.pop();

			if(s.empty()){

				int width=i;
				maxArea=max(maxArea,width*height);
			}

			else{

				int width=(i-s.top())-1;

				maxArea=max(maxArea,width*height);

			}


		}


	return maxArea;
}

int main(){

	// string str;

	// str="(())";

	// cout<<balancedparanthesis(str);




	// string str;

	// str="((((a+(b))+(c+d))))";

	// if(duplicate(str)){
	// 	cout<<"Yes";
	// }
	// else
	// {
	// 	cout<<"No";
	// }



// int arr[]={5,6,2,1,8,9};

// nextgraeterelemntsequencewiseprint(arr,6);
// nextsmallerelemntsequencewiseprint(arr,6);

// nextGreater(arr,6);




// int arr[]={100,80,60,70,60,75,85};

// stockspan(arr,7);


int arr[]={6, 2, 5, 4, 5, 1, 6};

cout<<histogram(arr,7);

}