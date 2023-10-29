//components of a graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
	public:
		int n;
		vector<vector<int> > graph;
		bool wt;
		bool dir;
		int start;
		Graph()
		{
			n=0;
//			graph=NULL;
		}
		void createGraph()
		{
			cout<<"\nEnter n : ";
			cin>>n;
			cout<<"\nEnter if weighted or not : ";
			cin>>wt;
			cout<<"\nEnter directed or undirected : ";
			cin>>dir;
//			for(int i=0;i<n;i++)
//			{
//				for(int j=0;j<n;j++)
//				{
//					graph[i][j]=0;
//				}
//			}
		}
		void readbyMat()
		{
			cout<<"\nEnter Graph : ";
			for(int i=0;i<n;i++)
			{
				int x;
				vector<int> temp;
				for(int j=0;j<n;j++)
				{
					cin>>x;
					temp.push_back(x);
				}
				graph.push_back(temp);
			}
		}
//		void readbyEdge()
//		{
//			int u,v;
//			cout<<"\nEnter the edges = ";
//			while(1)
//			{
//				cin>>u>>v;
//				if(u==-1||v==-1)
//				{
//					break;
//				}
//				insertEdge(u,v);
//			}
//		}
//		void insertEdge(int u,int v)
//		{
//			graph[u][v]=1;
//			if(!dir)
//			{
//				graph[v][u]=1;
//			}
//		}
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
		void bfs_traversal(int v)
		{
			queue<int> q;
			int* visited=new int[n];
			for(int i=0;i<n;i++)
			{
				visited[i]=0;
			}
			q.push(v);
			while(!q.empty())
			{
				visited[v]=1;
				v=q.front();
				cout<<v<<" ";
				q.pop();
				for(int i=0;i<n;i++)
				{
					if(graph[v][i]!=0 && visited[i]==0 )
					{
						visited[i]=1;
						q.push(i);
					}
				}
			}
		}
		void dfs_traversal()
		{
			int v;
			int* visited=new int[n];
			for(int i=0;i<n;i++)
			{
				visited[i]=0;
			}
			cout<<"\nEnter the beginning vertex = ";
			cin>>v;
			dfs_rec(visited,v);
		}
		void dfs_rec(int* visited,int v)
		{
			cout<<v<<"visited"<<endl;
			visited[v]=1;
			for(int i=0;i<n;i++)
			{
				if(graph[v][i]!=0 && visited[i]==0)
				{
					dfs_rec(visited,i);
				}
			}
		}
		void components()
		{
			int v;
			int* visited=new int[n];
			for(int i=0;i<n;i++)
			{
				visited[i]=0;
			}int cnt=0;
			for(int v=0;v<n;v++)
			{
				if(visited[v]==0)
				{
					dfs_rec(visited,v);
					cnt++;
				}
			}
			cout<<"\nComponents are = "<<cnt;
		}
		void warshall()
		{
			int tc[10][10];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					tc[i][j]=graph[i][j];
				}
			}
//			cout<<"*******************************";
//			for(int i=0;i<n;i++)
//			{
//				for(int j=0;j<n;j++)
//				{
//					cout<<tc[i][j]<<" ";
//				}cout<<endl;
//			}
			int i,j,k;
			for(k=0;k<n;k++)
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if(tc[i][j]==0)
						{
							if(tc[i][k]==1 && tc[k][j]==1)
							{
								tc[i][j]=1;
							}
						}
					}
				}
			}
			cout<<"TRANSITIVE CLOSURE : ";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						cout<<tc[i][j]<<" ";
					}cout<<endl;
				}
		}
		
};
int main()
{
	Graph g;
	g.createGraph();
	g.readbyMat();
	g.finddegree();
	g.components();
	return 0;
}
