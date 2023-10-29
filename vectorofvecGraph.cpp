//NON WEIGHTED
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
		}
		void createGraph()
		{
			cout<<"\nEnter n : ";
			cin>>n;
			cout<<"\nEnter if weighted or not : ";
			cin>>wt;
			cout<<"\nEnter directed or undirected : ";
			cin>>dir;
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
};
int main()
{
	Graph g;
	g.createGraph();
	g.readbyMat();
	g.finddegree();
	return 0;
}
