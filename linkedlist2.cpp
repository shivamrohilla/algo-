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

node* midpoint(node* head){

	if(head==NULL){

		cout<<"NO Linked list exist";
		return head;
	}

	node* slow=head;
	node* fast=head;

	while(fast->next != NULL and fast->next->next != NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;

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

void deleteathead(node* &head)
{
	if(head==NULL)
	{
		cout<<"Delete operation cannot be perfomed.";
	}

	node* temp=head;
	head=head->next;

	delete(temp);
}

void deleteattail(node* head){

	while(head->next->next != NULL){
		head=head->next;

	}

	node* temp=head;
	head=head->next;
	temp->next=NULL;
	delete(head);
}

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

node* kthfromlast(node* head,int idx){


	if(head->next==NULL){
		return head;
	}
	int jump=idx-1;
	node* slow=head;
	node* fast=head;

	while(jump !=0 and fast != NULL){

		fast=fast->next;
		jump--;
	}

	if(fast==NULL)
	{
		return head;
	}

	while(fast->next != NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}

	return slow;

}

node* kreverse(node* head, int k)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}

	node* prev=NULL;
	node* curr=head;

	int count=1;

	while(count<=k and curr != NULL)
	{
		node* n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
		count++;
	}

	head->next=kreverse(curr,k);
	 return prev;
}
node* l;

bool helper(node* right){

	if(right==NULL){
		return true;
	}

	bool recres=helper(right->next);
	bool ans;
	if( recres and right->data==l->data){
		ans=true;

	}
	else{
		ans=false;
	}
	l=l->next;

	return ans;
}



bool ispalindrome(node* head){
	l=head;
	return helper(head);
}


void listkappend(node* &head,int k){

	node* temp=kthfromlast(head,k+1);
	node* kth=temp->next;
	temp->next=NULL;
	temp=kth;
	while(kth->next != NULL)
	{
		kth=kth->next;
	}
	kth->next=head;
	head=temp;


}
node* merge(node* a,node* b,int x)
{
	if(a==NULL){
		return b;

	}

	if(b==NULL)
	{
		return a;
	}


	node* c;

	if((a->data<x and b->data<x) or (a->data>=x and b->data>=x)){
		c=a;
		c->next=b;
		c->next->next=merge(a->next,b->next,x);
	}

	if(a->data<x and b->data>=x)
	{
		c=a;
		c->next=merge(a->next,b,x);
	}
	if(a->data>=x and b->data<x)
	{
		c=b;
		c->next=merge(a,b->next,x);
	}

	return c;
}
void partition(node* &head,int x)
{
	if(head==NULL)
	{
		return;
	}

	node* mid=midpoint(head);
	node* mid2=mid->next;
	mid->next=NULL;
	partition(head,x);
	partition(mid2,x);


	head=merge(head,mid2,x);
}
int main(int argc, char const *argv[])
{
	
	node* head=NULL;

	insertathead(head,5);
	insertathead(head,4);
	insertathead(head,3);
	insertathead(head,2);
	insertathead(head,1);

	insertattail(head,6);
	insertattail(head,7);



	//display(head);

	// // cout<<"Kth from last---------------"<<endl;

	// // cout<<kthfromlast(head,3)->data<<endl;


	// // cout<<"K reverse of linked list-------------------"<<endl;

	// // head=kreverse(head,3);

	// // display(head);

	// node* head=NULL;

	// insertattail(head,1);
	// insertattail(head,2);
	// insertattail(head,2);
	// insertattail(head,1);

	// display(head);

	// if(ispalindrome(head)){
	// 	cout<<"This is palindrome";
	// }
	// else{
	// 	cout<<"This is not palindrome";
	// }


	cout<<"K-------------append"<<endl;

	listkappend(head,7);
	display(head);


	// insertathead(head,1);
	// insertathead(head,4);
	// insertathead(head,3);
	// insertathead(head,2);
	// insertathead(head,5);

	// insertattail(head,2);

	

	// display(head);

	return 0;
}