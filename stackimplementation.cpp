#include <iostream>
using namespace std;

template <typename T>

class Stack{

	T *arr;
	int maxsize;
	int top;

public:
	Stack(int capacity=5){

		this->maxsize=capacity;
		this->arr=new T[this->maxsize];
		this->top=-1;
	}


	void push(T data){


		if(this->top==maxsize-1){
			cout<<"Stack is full"<<endl;
			return;
		}

		this->top++;
		this->arr[this->top]=data;


	}

	void pop(){

		if(this->top==-1){

			cout<<"Stack is underflow"<<endl;
			return;
		}

		this->top--;

	}

	T getTop(){

		if(this->top==-1){
			cout<<"Stack  is empty";
			return this->arr[this->top];
		}
		return this->arr[this->top];
	}

	int size(){

		return this->top+1;
	}

	bool  isempty(){

		return this->size()==0;
	} 





};

int main(int argc, char const *argv[])
{
	Stack<int> s;

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	cout<<s.size()<<endl;
	cout<<s.getTop()<<endl;


	return 0;
}