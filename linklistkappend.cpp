#include<iostream>
using namespace std;

class node{
	
public:

	int data;
	node* next;

	node(int data){
		this->data=data;
		this->next=NULL;
	}
};

void display(node* head){

	if(head==NULL)
	{
		cout<<"NULL";
	}

	while(head != NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}

void insertathead(node* &head,int data)
{	

	node* n= new node(data);
	n->next=head;
	head=n;
}

void insertattail(node* &head,int data)
{
	if(head==NULL)
	{
		insertathead(head,data);
		return;
	}
	node* n=new node(data);
	node* temp=head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}

void kappend(node* &head,int k){

	int jump=k;
	node* slow=head;
	node* fast=head;
	while(jump != 0){
		fast=fast->next;
		if(fast==NULL){
			return;
		}
		jump--;
	}


	while(fast->next != NULL){
		slow=slow->next;
		fast=fast->next;
	}

	fast->next=head;
	head=slow->next;
	slow->next=NULL;


}

int main(int argc, char const *argv[])
{

	node* head=NULL;
	
	insertattail(head,1);
	insertattail(head,2);
	insertattail(head,3);
	insertattail(head,4);
	insertattail(head,5);
	insertattail(head,6);
	insertattail(head,7);
	insertattail(head,8);

	display(head);

	kappend(head,9);

	display(head);

	cout<<1%100;

	return 0;
}