//Remember the convention
//left bit and right bit represent the links -- 0 -threaded link & 1--normal link
//child --represents if the node is left or right child -- 0--left child & 1--right child
//left and right poimters represent the left and right nodes
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* left,*right;
		int lbit,rbit;
		int child;
		Node()
		{
			data=0;
			child=-1;//not left or right child
			lbit=rbit=0;//thread link
			left=right=NULL;
		}
		Node(int x)
		{
			data=x;
			child=-1;
			lbit=rbit=0;
			left=right=NULL;
		}
};
class TBT
{
	Node* root;
	public:
		TBT()
		{
			root= new Node(-1);
			root->left=root;
			root->right=root;
			root->lbit=1;
		}
		void create_rec(Node* father,int child);
		void create();
		void inorder_nonrec();
		Node* inorder_succ(Node*);
		void preorder();
		Node* preorder_succ(Node*);
};
void TBT::inorder_nonrec()
{
	Node* temp=root->left;
	while(temp->lbit==1)
	{
		temp=temp->left;
	}
	while(temp!=root)
	{
		cout<<temp->data<<" ";
		temp=inorder_succ(temp);
	}
}
Node* TBT::inorder_succ(Node* T)
{
	if(T->rbit==0)
	{
		//T->right is the successor
		T=T->right;
	}
	else
	{
		T=T->right;
		while(T->lbit==1)
		{
			T=T->left;
		}
	}
	return T;
}
void TBT::preorder()
{
	Node* temp=root->left;
	while(temp!=root)
	{
		cout<<temp->data<<" ";
		temp=preorder_succ(temp);
	}
}
Node* TBT::preorder_succ(Node* T)
{
	if(T->lbit==1)
	{
		T=T->left;
	}
	else
	{
		while(T->rbit==0 && T!=root)
		{
			T=T->right;
		}
		T=T->right;
	}
	return T;
}
void TBT::create()
{
	create_rec(root,0);
}
void TBT::create_rec(Node* father,int child)
{
	int x;
	cout<<"\nEnter the data = ";
	cin>>x;
	if(x==0)
	{
		return;
	}
	Node* T=new Node(x);
	if(child==0)
	{
		T->left=father->left;
		T->right=father;
		T->child=0;
		father->left=T;
		father->lbit=1;
	}
	else if(child==1)
	{
		T->left=father;
		T->right=father->right;
		T->child=1;//right child
		father->right=T;
		father->rbit=1;
	}
	cout<<"\nEnter the left child of = "<<x;
	create_rec(T,0);
	cout<<"\nEnter the right child of = "<<x;
	create_rec(T,1);
}
int main()
{
	TBT t1;
	t1.create();
	t1.inorder_nonrec();
	return 0;
}
