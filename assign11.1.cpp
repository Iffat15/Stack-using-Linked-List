#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node(int x)
		{
			data=x;
			next=NULL;
		}
};
class Stack
{
	Node* top;
	public:
		Stack()
		{
			top=NULL;	
		}
		void push(int x);	
		int pop();
		int isempty();
};
int Stack::isempty()
{
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}
void Stack::push(int x)
{
	Node* p=NULL;
	p=new Node(x);
	p->next=top;
	top=p;
}
int Stack::pop()
{
	if(top==NULL)
	{
		return -1;
	}
	Node* p=NULL;
	p=top;
	int x=p->data;
	top=top->next;
	return x;
}
int main()
{
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout<<stk.pop()<<" ";
	cout<<stk.pop()<<" ";
	cout<<stk.pop()<<" ";
	cout<<stk.pop()<<" ";
	cout<<stk.isempty()<<" ";
	return 0;
}
