#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class TreeNode{

public:

	int val;
	TreeNode* right;
	TreeNode* left;

	TreeNode(int data){

		this->val=data;
		this->left=NULL;
		this->right=NULL;
	}
};


TreeNode* buildtree(TreeNode* root){

	int data;
	cin>>data;


	if(data==-1){

		return NULL;
	}

	if(root==NULL){

		root= new TreeNode(data);
	}

	root->left=buildtree(root->left);
	root->right=buildtree(root->right);

	return root;


}


TreeNode* builtBST(TreeNode* root,int data){

	if(root==NULL){

		return new TreeNode(data);
	}

	if(data>root->val){

		root->right=builtBST(root->right,data);
	}
	else
	{
		root->left=builtBST(root->left,data);
	}


	return root;

}


TreeNode* insert(){

	TreeNode* root=NULL;
	int data;

	cin>>data;

	while(data!=-1){

		root=builtBST(root,data);
		cin>>data;
	}

	return root;
}

TreeNode* insertBlances(int arr[],int n){

	TreeNode* root =NULL;
	int mid=n/2;

	int left=mid-1;
	int right=mid+1;
	root=builtBST(root,arr[mid]);



	while(left>=0 and right<n){

		root=builtBST(root,arr[left]);
		root=builtBST(root,arr[right]);
		left--;
		right++;

	}

	if(left>=0){

		root=builtBST(root,arr[left]);
		left--;
	}

	if(right<n){

		root=builtBST(root,arr[right]);
		right++;
	}

	return root;

}

int height(TreeNode* root){

	if(root==NULL){
		return -1;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	return max(lh,rh)+1;
}


class balancedheight{

public:

	int height;
	bool status;
};

balancedheight OptiIsBlancedTree(TreeNode* root){

	balancedheight res;

	if(root==NULL){

		res.height=-1;
		res.status=true;
        return res;
	}

	balancedheight LeftkaHaalChaal=OptiIsBlancedTree(root->left);
	balancedheight RightkaHaalChaal=OptiIsBlancedTree(root->right);

	int leftkiheight=LeftkaHaalChaal.height;
	int rightkiheight=RightkaHaalChaal.height;
	res.height=max(leftkiheight,rightkiheight)+1;


	if(LeftkaHaalChaal.status and RightkaHaalChaal.status){

		
		if(abs(rightkiheight- leftkiheight)==0 or abs(rightkiheight- leftkiheight)==1){

			res.status=true;
            return res;
		}

	}

	res.status=false;
	return res;



}

void preorder(TreeNode* root){

	if(root==NULL){

		return;
	}

	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root){

	if(root==NULL){

		return;
	}

	
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}
void inorder(TreeNode* root){

	if(root==NULL){

		return;
	}

	
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

bool isBST(TreeNode* root,int min=INT8_MIN,int max=INT8_MAX){

	if(root==NULL){

		return true;
	}

	if(root->val>min and root->val<max){

		return isBST(root->left,min,root->val) and isBST(root->right,root->val,max);
	}

	return false;
}


int main(int argc, char const *argv[])
{
	
	TreeNode* root=NULL;

	// root=buildtree(root);
	// root=insert();


	//inorder(root);

	//cout<<isBST(root);

	int arr[]={1,2,3,4,5,6,7,8};
	root=insertBlances(arr,8);

	inorder(root);
	cout<<endl;
	cout<<OptiIsBlancedTree(root).status;
	cout<<height(root);
	return 0;
}

//4 2 1 3 6 5 7 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1