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
			//initialise the top pointer to NULL
			top=NULL;	
		}
		void push(int x);	
		int pop();
		int isempty();
};
int Stack::isempty()
{
	//returns 1 for empty stack
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}
void Stack::push(int x)
{
	//returns 1 for full stack
	Node* p=NULL;
	p=new Node(x);
	p->next=top;
	top=p;
}
int Stack::pop()
{
	//pop function removes the top element and returns it
	if(top==NULL)
	{
		//if stack is empty
		return -1;
	}
	Node* p = NULL;
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
