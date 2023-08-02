#include<iostream>
#define max 5
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node()
		{
			data=0;
			next=NULL;
		}
		Node(int x)
		{
			data=x;
			next=NULL;
		}
};
class Stack
{
	int data[max];
	int top1,top2;
	public:
		Stack()
		{
			top1=-1;
			top2=max;	
		}	
		void push(int stno,int x);
		int pop(int stno);
		int isempty(int stno);
		int isfull();
};
int Stack::isempty(int stno)
{
	if(stno==1)
	{
		if(top1==-1)
		{
			return 1;
		}
		return 0;
	}
	else if(stno==2)
	{
		if(top2==max)
		{
			return 1;
		}
		return 0;
	}
}
int Stack::isfull()
{
	if(top1+1==top2)
	{
		return 1;
	}
	return 0;
}
void Stack::push(int stno,int x)
{
	if(stno==1)
	{
		top1++;
		data[top1]=x;
	}
	else
	{
		top2--;
		data[top2]=x;
	}
}
int Stack::pop(int stno)
{
	if(stno==1)
	{
		int x=data[top1];
		top1--;
		return x;
	}
	else if(stno==2)
	{
		int x=data[top2];
		top2++;
		return x;
	}
}
int main()
{
	Stack stk;
	stk.push(1,12);
	stk.push(1,29);
	stk.push(2,89);
	stk.push(2,19);
	stk.push(1,21);
	cout<<"Is full = "<<stk.isfull()<<" \n";
	cout<<stk.pop(2)<<" ";
	cout<<stk.pop(1)<<" ";
	cout<<stk.pop(2)<<" ";
	cout<<stk.pop(1)<<" ";
	cout<<stk.pop(1)<<" ";
	cout<<stk.pop(2)<<" ";
	cout<<stk.isfull()<<" ";
	return 0;
}
