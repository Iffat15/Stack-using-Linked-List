#include<iostream>
#include<vector>
using namespace std;
void subsequences(vector<int> vec,int ind, vector<vector<int> >& ans,vector<int>& res)
{
	if(ind==3)
	{
		ans.push_back(res);
		return;
	}
	else
	{
		res.push_back(vec[ind]);
		subsequences(vec,ind+1,ans,res);
		
		res.pop_back();
		subsequences(vec,ind+1,ans,res);
	}
}
int main()
{
	vector<int> vec(3);
	cout<<"\nEnter the elements of vector = ";
	for(int i=0;i<3;i++)
	{
		cin>>vec[i];
	}
	vector<vector<int> > ans;
	vector<int> res;
	subsequences(vec,0,ans,res);
	cout<<"\nThe subsequences are = \n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<"[";
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"]";
		
		cout<<endl;
	}
}
