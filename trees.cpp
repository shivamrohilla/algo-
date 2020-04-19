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

int height(TreeNode* root){

	if(root==NULL){
		return -1;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	return max(lh,rh)+1;
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

int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int total = leftCount + rightCount + 1;
	return total;
}


int replaceSum(TreeNode* root) {
	if (root == NULL) return 0;

	if (root->left == NULL and root->right == NULL) {
		return root->val;
	}

	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->val;
	root->val = leftSum + rightSum;

	return root->val + temp;
}

// Time: O(n)
bool issameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool leftSubtreeCheck = issameTree(p->left, q->left);
	bool rightSubtreeCheck = issameTree(p->right, q->right);

	if (leftSubtreeCheck and rightSubtreeCheck) {
		return true;
	}

	return false;
}

int diameter(TreeNode* root){


	if(root==NULL){
		return 0;
	}

	int leftkiheight=height(root->left);
	int rightkiheight=height(root->right);
	int total=leftkiheight+rightkiheight+2;

	int rightdia=diameter(root->left);
	int leftdia=diameter(root->right);

	return max(max(rightdia,leftdia),total);
}

class DiaHeight{

public:
	int height;
	int diameter;
};


DiaHeight OptimisedDiameterOfBinaryTree(TreeNode* root){

	DiaHeight res;
	if(root==NULL){

		res.height=-1;
		res.diameter=0;
		return res;
	}

	DiaHeight leftkamaal=OptimisedDiameterOfBinaryTree(root->left);
	DiaHeight rightkamaal=OptimisedDiameterOfBinaryTree(root->right);
	int leftkiheight=leftkamaal.height;
	int rightkiheight=rightkamaal.height;


	int merethrough=leftkiheight+rightkiheight+2;

	int rightdia=rightkamaal.diameter;
	int leftdia=leftkamaal.diameter;

	res.height=max(leftkiheight,rightkiheight)+1;
	res.diameter=max(max(rightdia,leftdia),merethrough);

	return res;



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

void leafpaths(TreeNode* root,vector<int> path){

	if(root->left==NULL and root->right==NULL){

		path.push_back(root->val);
		for(int i=0;i<path.size();i++){

			cout<<path[i]<<" ";
		}
		path.pop_back();
		cout<<endl;
		return;
	}

	path.push_back(root->val);
	leafpaths(root->left,path);
	leafpaths(root->right,path);
	path.pop_back();


}

//leetcode
 TreeNode* Mirror(TreeNode* root){
        
        if(root==NULL){
            return NULL;
        }
        
        TreeNode* node=new TreeNode(root->val);
        node->left=Mirror(root->right);
        node->right=Mirror(root->left);
        
        
        return node;
    }
    
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool leftSubtreeCheck = isSameTree(p->left, q->left);
	bool rightSubtreeCheck = isSameTree(p->right, q->right);

	if (leftSubtreeCheck and rightSubtreeCheck) {
		return true;
	}

	return false;
}

bool isSymmetric(TreeNode* root) {
        
    
      TreeNode* mirror=Mirror(root);  
        
     return isSameTree(root,mirror);   
        
        
        
    }
    


 bool helper(TreeNode* p,TreeNode* q){
        
        if(p==NULL and q==NULL){
            return true;
        }
        
        if(p==NULL or q==NULL){

        return false;
        }
        
        
        if(p->val!=q->val){

        return false;
        }
        
        
        return helper(p->left,q->right) and helper(p->right,q->left);
    }
   

bool isSymmetric2(TreeNode* root) {
        
    if(root==NULL){
        return true;
    }
        
     return helper(root->left,root->right);   
        
        
        
    }
    
    
    
   



void levelorder(TreeNode* root){

	queue<TreeNode*> q;

	q.push(root);
	
	while(!q.empty()){

		TreeNode* temp=q.front();
		q.pop();

		cout<<temp->val<<" ";

		if(temp->left != NULL){

			q.push(temp->left);
		}

		if(temp->right != NULL){

			q.push(temp->right);
		}


	}
}

void levelordernextline(TreeNode* root){


	queue<pair<TreeNode*,int >> q;

	q.push({root,1});

	int currentlevel=1;

	while(!q.empty()){

		pair<TreeNode* , int> temp=q.front();
		q.pop();

		TreeNode* node=temp.first;
		int level=temp.second;

		if(level>currentlevel){

		cout<<endl;
		currentlevel++;
		}

		cout<<node->val<<" ";

		if(node->left != NULL){

			q.push({node->left,level+1});
		}



		if(node->right != NULL){

			q.push({node->right,level+1});
		}
	}
}

void levelordernextlinebetter(TreeNode* root){

	queue<TreeNode*> q;

	q.push(root);
	
	while(!q.empty()){

		int len=q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp=q.front();
			q.pop();

		cout<<temp->val<<" ";

		if(temp->left != NULL){

			q.push(temp->left);
		}

		if(temp->right != NULL){

			q.push(temp->right);
		}


		}

		cout<<endl;


	}

}

//leetcode
int  maxsumpath(TreeNode* root,int &maxsum){
        
        if(root==NULL){
            
            return 0;
        }
        
        int leftsum=maxsumpath(root->left,maxsum);
        int rightsum=maxsumpath(root->right,maxsum);
        
        leftsum=max(0,leftsum);
        rightsum=max(0,rightsum);
        
        
        maxsum=max(maxsum,leftsum+rightsum+root->val);
        
        return max(leftsum,rightsum)+root->val;
    }


void leftview(TreeNode* root){


	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){

		int len=q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp=q.front();
			q.pop();

			if(i==0){

				cout<<temp->val<<" ";
			}


			if(temp->left != NULL){

			q.push(temp->left);
		}

		if(temp->right != NULL){

			q.push(temp->right);
		}


		}
	}
}

int FirstLevel=1;

void leftviewRec(TreeNode* root,int level){

	if(root==NULL){
		return;
	}

	if(level==FirstLevel){

		cout<<root->val<<" ";
		FirstLevel++;
	}

	leftviewRec(root->left,level+1);
	leftviewRec(root->right,level+1);




}

//boundaryview 

void leafnodes(TreeNode* root){
	if(root==NULL){


		return;
	}
	if(root->left==NULL and root->right==NULL){


		cout<<root->val<<" ";
		return;

	}

	leafnodes(root->left);
	leafnodes(root->right);



}

void leftboundary(TreeNode* root){

	if(root==NULL){

		return;
	}

	if(root->left==NULL and root->right==NULL){

		return;
	}


	cout<<root->val<<" ";

	if(root->left != NULL){

		leftboundary(root->left);
	}
	else{

		leftboundary(root->right);
	}
}


void rightBoundary(TreeNode* root){


	if(root==NULL){

		return;
	}

	if(root->left==NULL and root->right==NULL){

		return;
	}


	

	if(root->right != NULL){

		rightBoundary(root->right);
	}
	else{

		rightBoundary(root->left);
	}

	cout<<root->val<<" ";
}


void boundaryview(TreeNode* root){

	leftboundary(root);
	leafnodes(root);
	rightBoundary(root->right);
}

void leveFirstandLastElementPrint(TreeNode* root){


	queue<TreeNode*> q;
	stack<TreeNode*> s;

	q.push(root);

	while(!q.empty()){

		int len=q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp=q.front();
			q.pop();

			if(i==0 ){

				cout<<temp->val<<" ";
			}

			if(i==len-1 and i !=0 ){

				s.push(temp);
			}


			if(temp->left != NULL){

			q.push(temp->left);
		}

		if(temp->right != NULL){

			q.push(temp->right);
		}


		}
	}

	

	while(!s.empty()){

		cout<<s.top()->val<<" ";
		s.pop();
	}
}    


void klevelstore(TreeNode* root  , std::vector<int> &v,int k){

	queue<TreeNode*> q;
	int currentlevel=-1;
	q.push(root);

	while(!q.empty()){

		currentlevel++;

		if(currentlevel>k){
			return;
		}

		int len=q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp=q.front();
			q.pop();

			if(currentlevel==k){
				v.push_back(temp->val);
				continue;
			}

		if(temp->left != NULL){

			q.push(temp->left);
		}

		if(temp->right != NULL){

			q.push(temp->right);
		}


		}



	}

}



bool LeastCommonAncestor(TreeNode* root,int x,int y, TreeNode* &LCA){ //LeetCode Submitted

	if(root == NULL){

		return false;
	}

	if(root->val==x or root->val==y){

		bool leftcheck=LeastCommonAncestor(root->left,x,y,LCA);

	bool rightcheck=LeastCommonAncestor(root->right,x,y,LCA);

	if(rightcheck or leftcheck){

		cout<<root->val;
		LCA=root;

		return true;
	}



		return true;
	}

	bool leftcheck=LeastCommonAncestor(root->left,x,y,LCA);

	bool rightcheck=LeastCommonAncestor(root->right,x,y,LCA);

	if(rightcheck and leftcheck){

		cout<<root->val;
		LCA=root;

		return true;
	}
	else{

		return rightcheck or leftcheck;
	}

}


TreeNode* LCABhaiyaVala(TreeNode* root,int x,int y){

	if(root==NULL){

		return NULL;
	}

	if(root->val==x or root->val==y){

		return root;
	}

	TreeNode* Leftkabatao=LCABhaiyaVala(root->left,x,y);
	TreeNode* Rightkabatao=LCABhaiyaVala(root->right,x,y);

	if(Leftkabatao and Rightkabatao){

		return root;
	}

	if(Leftkabatao==NULL and Rightkabatao==NULL){

		return NULL;
	}

	return Leftkabatao==NULL ? Rightkabatao : Leftkabatao;
}

int isLevelKarightde=1;

void rightviewRec(TreeNode* root,int level){

	if(root==NULL){

		return;
	}

	if(level==isLevelKarightde){

		cout<<root->val<<" ";
		isLevelKarightde++;
	}

	rightviewRec(root->right,level+1);
	rightviewRec(root->left,level+1);



}

void rightview(TreeNode* root){

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){

		int len=q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp=q.front();
			q.pop();

			if(i==len-1){
				cout<<temp->val<<" ";
			}

			if(temp->left){
				q.push(temp->left);
			}

			if(temp->right){
				q.push(temp->right);

			}
		}
	}
}


int main(int argc, char const *argv[])
{
	 

	TreeNode* root=NULL;

	root=buildtree(root);


	// preorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;

	// cout<<countNodes(root)<<endl;
	// cout<<height(root);

	//vector<int> path;
	//leafpaths(root,path);


	//levelordernextline(root);



	//boundaryview(root);



	// std::vector<int> v;
	// klevelstore(root,v,3);

	// for(int i:v){

	// 	cout<<i<<" ";
	// }

	//TreeNode* Lca;
	//LeastCommonAncestor(root,7,9,Lca);
	//cout<<Lca->val<<endl;

	//cout<<LCABhaiyaVala(root,7,9)->val;


	//leftviewRec(root,1);

	//boundaryview(root);


	//rightviewRec(root,1);

	rightview(root);

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1