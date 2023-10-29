#include<iostream>
#include<vector>
using namespace std;
struct item
{
	double profit;
	double weight;
	double pw;
	double x;
};
int main()
{
	int n;
	double m;
	cout<<"\nEnter the number of items = ";
	cin>>n;
	cout<<"\nEnter the maximum weight of the knapsack = ";
	cin>>m;
	item *p=new item[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter profit of "<<i<<"th item = ";
		cin>>(*(p+i)).profit;
		cout<<"\nEnter weight of "<<i<<"th item = ";
		cin>>(*(p+i)).weight;
		(*(p+i)).pw=(double)(*(p+i)).profit/(*(p+i)).weight;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((*(p+i)).pw<(*(p+j)).pw)
			{
				swap(*(p+i),*(p+j));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<((*(p+i)).pw)<<" ";
	}
	int i=0;double pro=0;cout<<endl;
	while(m>0)
	{
		if((*(p+i)).weight<=m)
		{
			m=m-(*(p+i)).weight;
			(*(p+i)).x=1;
		}
		else
		{
			(*(p+i)).x=(m/(*(p+i)).weight);
			m=0;
		}
		pro=pro+(((*(p+i)).x)*(*(p+i)).profit);
		cout<<pro<<" ";i++;
	}
	cout<<"\nProfit = "<<pro;
}
