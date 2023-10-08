#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>
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
		int height(Node* T);
		void kthdist(Node*,int dist,int k,vector<Node*>& vec);
};
void BinaryTree::kthdist(Node* T,int dist,int k,vector<Node*>& vec)
{
	if(T==NULL)
	{
		return;
	}
	if(dist==k)
	{
		vec.push_back(T);
	}
	dist++;
	if(T->left!=NULL)
	{
		kthdist(T->left,dist,k,vec);
	}
	if(T->right!=NULL)
	{
		kthdist(T->right,dist,k,vec);
	}
}
int BinaryTree::height(Node* T)
{
	if(T==NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 1;
	}
	int hl=0;int hr=0;
	if(T->left!=NULL)
	{
		hl=1+height(T->left);
	}
	if(T->right!=NULL)
	{
		hr=1+height(T->right);
	}
	int max=hl>hr?hl:hr;
	return max;
}
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
	vector<Node*> res;
	int sum=0;
	int k;
	cout<<"\nEnter the distance = ";
	cin>>k;
	t.kthdist(r,sum,k,res);
	cout<<"\n\n";
	for(int i=0;i<res.size();i++)
	{
		Node* temp=res[i];
		cout<<temp->data<<" ";
	}
	return 0;
}
