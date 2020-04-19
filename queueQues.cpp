#include <iostream>
#include <queue>

using namespace std;

void FirstNonrepeatinhChar(){


	queue<char> q;
	int freq[256]={0};

	while(1){

		char ch;
		cin>>ch;

		if(ch=='.'){

			break;
		}

		freq[ch] += 1;
		q.push(ch);


		while(!q.empty() and freq[q.front()]>1){

			q.pop();
		}

		if(q.empty()){

			cout<<-1<<" ";
		}

		else{

			cout<<q.front()<<" ";
		}
	}
}

int main(int argc, char const *argv[])
{
	


	FirstNonrepeatinhChar();
	return 0;
}