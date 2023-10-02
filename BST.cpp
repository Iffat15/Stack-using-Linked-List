#include<iostream>
#include<stack>
using namespace std;
class Node
{
	public:
		int data;
		Node* left,*right;
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
class BST
{
	Node* root;
	public:
		BST()
		{
			root=NULL;
		}
		void create();
		void create_rec(int x);	
		void inorder_nonrec(Node* T);
		Node* getroot();
};
Node* BST::getroot()
{
	return root;
}
void BST::inorder_nonrec(Node* T)
{
	stack<Node*> stack;
	while(T!=NULL)
	{
		stack.push(T);
		T=T->left;
	}
	while(!stack.empty())
	{
		T=stack.top();
		stack.pop();
		cout<<T->data<<" ";
		T=T->right;
		while(T!=NULL)
		{
			stack.push(T);
			T=T->left;
		}
	}
}
void BST::create_rec(int x)
{
	Node* T=NULL;
	Node* q=NULL;
	T=root;
	if(root==NULL)
	{
		root=new Node(x);
		return;
	}
	while(T!=NULL)
	{
		q=T;
		if(x < T->data)
		{
			T=T->left;
		}
		else if(x > T->data)
		{
			T=T->right;
		}
		else
		{
			cout<<"\nDuplicate Node !!";
			return;
		}
	}
	if(x < q->data)
	{
		q->left=new Node(x);
	}
	else if( x > q->data)
	{
		q->right=new Node(x);
	}
}
void BST::create()
{
	int x;
	cout<<"\nKeep entering : ";
	while(1)
	{
		cout<<"\nEnter data = ";
		cin>>x;
		if(x==0)
		{
			break;
		}
		create_rec(x);
	}
}
int main()
{
	BST b;
	b.create();
	Node* r=b.getroot();
	b.inorder_nonrec(r);
	return 0;
}
