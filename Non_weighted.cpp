//NON WEIGHTED
#include<iostream>
using namespace std;
class Graph
{
	public:
		int n;
		int** graph;
		bool wt;
		bool dir;
		int start;
		Graph()
		{
			n=0;
			graph=NULL;
		}
		void createGraph()
		{
			cout<<"\nEnter n : ";
			cin>>n;
			cout<<"\nEnter if weighted or not : ";
			cin>>wt;
			cout<<"\nEnter directed or undirected : ";
			cin>>dir;
			graph = new int*[n];
			for(int i=0;i<n;i++)
			{
				graph[i]=new int[n];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					graph[i][j]=0;
				}
			}
		}
		void readbyMat()
		{
			cout<<"\nEnter Graph : ";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>graph[i][j];
				}
			}
		}
		void readbyEdge()
		{
			int u,v;
			cout<<"\nEnter the edges = ";
			while(1)
			{
				cin>>u>>v;
				if(u==-1||v==-1)
				{
					break;
				}
				insertEdge(u,v);
			}
		}
		void insertEdge(int u,int v)
		{
			graph[u][v]=1;
			if(!dir)
			{
				graph[v][u]=1;
			}
		}
		void displayMat()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<graph[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void indegree()
		{
			int i,j;
			for(int i=0;i<n;i++)
			{
				int j;int count=0;
				for(j=0;j<n;j++)
				{
					if(graph[j][i]!=0)
					{
						count++;
					}
				}
				cout<<"\nIndegree of "<<i<<" is = "<<count;
			}cout<<endl;
		}
		void outdegree()
		{
			int i,j;
			for(int i=0;i<n;i++)
			{
				int j;int count=0;
				for(j=0;j<n;j++)
				{
					if(graph[i][j]!=0)
					{
						count++;
					}
				}
				cout<<"\nOutdegree of "<<i<<" is = "<<count;
			}cout<<endl;
		}
		void finddegree()
		{
			if(dir==1)
			{
				indegree();
				outdegree();
			}
			else
			{
				indegree();
			}
		}
};
int main()
{
	Graph g;
	g.createGraph();
	int choice;
	cout<<"\nEnter 1 for manually adding the matrix or 2 for directly edge = ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			g.readbyMat();
			break;
		case 2:
			g.readbyEdge();
			break;
	}
	g.finddegree();
	return 0;
}
