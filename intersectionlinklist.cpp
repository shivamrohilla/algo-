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
node* intersection(node* a,node* b){

	while(a != NULL or b != NULL)
	{
		if(a->data==b->data){
			return a;
		}
		a=a->next;
		b=b->next;


	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	node* a=NULL;
	node* b=NULL;


	insertattail(a,10);
	insertattail(a,20);
	insertattail(a,30);
	insertattail(a,40);
	insertattail(a,50);

	insertattail(b,15);
	insertattail(b,25);
	insertattail(b,40);
	insertattail(b,50);

	display(a);
	display(b);

	node* intersec=intersection(a->next,b);

	if(intersec != NULL){

		cout<<intersec->data<<"->";
	}
	else
	{
		cout<<-1;
	}
	return 0;
}