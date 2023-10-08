#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
class Node
{
	public:
		Node* left;
		int data;
		Node* right;
		Node()
		{
			data=0;
			left=right=NULL;
		}
		Node(int x)
		{
			data=x;
			left=right=NULL;
		}
};
class BinaryTree
{
	Node* root;
	public:
		Node* getroot();
		Node* creatrec();
		void create();
		void inorder_rec(Node*);
		void postorder_wrec(Node*);
		int count0(Node*);
		int count1(Node*);
};
int BinaryTree::count1(Node* T)
{
	if(T==NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right!=NULL)
	{
		return 1+count1(T->right);
	}
	if(T->left!=NULL && T->right==NULL)
	{
		return 1+count1(T->left);
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	return count1(T->left)+count1(T->right);
}
int BinaryTree::count0(Node* T)
{
	if(T==NULL)
	{
		return 0;
	}
	//o children
	if(T->left==NULL && T->right==NULL)
	{
		return 1;
	}
	//1 child
	if(T->left==NULL && T->right!=NULL)
	{
		return 0+count0(T->right);
	}
	//1 child
	if(T->left!=NULL && T->right==NULL)
	{
		return 0+count0(T->left);
	}
	//2 children
	return 0+count0(T->left)+count0(T->right);
	
}
Node* BinaryTree ::getroot()
{
	return root;
}
Node* BinaryTree::creatrec()
{
	int x;
	cout<<"\nEnter the data = ";
	cin>>x;
	Node* p=new Node(x);
	if(x==0)
	{
		return NULL;
	}
	else
	{
		cout<<"\nEnter the data for the left node of "<<p->data;
		p->left=creatrec();
		cout<<"\nEnter the data for the right node of "<<p->data;
		p->right=creatrec();
	}
	
}
void BinaryTree::create()
{
	root=creatrec();
}
void BinaryTree::inorder_rec(Node* T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		inorder_rec(T->left);
		cout<<T->data<<" ";
		inorder_rec(T->right);
	}
}
int main()
{
	BinaryTree t;
	t.create();
	Node* r = t.getroot();
	t.inorder_rec(r);
	cout<<"\nCount of nodes with O children = "<<t.count0(r)<<endl;
	cout<<"\nCount of nodes with 1 children = "<<t.count1(r);
	return 0;
}
