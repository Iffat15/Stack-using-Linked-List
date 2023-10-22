#include<iostream>
#define n 6
using namespace std;
class Node
{
	public:
		int vertex;
		Node* next;
		Node()
		{
			vertex=0;
			next=NULL;
		}
		Node(int x)
		{
			vertex=x;
			next=NULL;
		}
};
class Graph
{
	Node* head[n];
	public:
		bool dir,wt;
		int start;
		Graph()
		{
			for(int i=0;i<n;i++)
			{
				head[i]=NULL;
			}
		}
		void readbyEdges()
		{
			int u,v;
			cout<<"\nEnter u and v  = ";
			while(1)
			{
				cin>>u>>v;
				if(u==-1||v==-1)
				{
					break;
				}
				insertEdge(u,v);
				if(!dir)
				{
					insertEdge(v,u);
				}
			}
		}
		void insertEdge(int u,int v)
		{
			Node* p=head[u];
			if(head[u]==NULL)
			{
				head[u]=new Node(v);
			}
			else
			{
				while(p->next!=NULL)
				{
					if(p->vertex==v)
					{
						return;
					}
					p=p->next;
				}
				p->next=new Node(v);
			}
		}
		void printlist()
		{
			for(int i=0;i<n;i++)
			{
				Node* p = head[i];
				cout<<i<<"::";
				while(p!=NULL)
				{
					cout<<p->vertex<<"->";
					p=p->next;
				}
				cout<<"null"<<endl;
			}
		}
};
int main()
{
	Graph g;
	g.readbyEdges();
	g.printlist();
	return 0;
}
