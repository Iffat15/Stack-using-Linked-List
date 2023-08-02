#include<iostream>
using namespace std;
int TOH(int n,char S,char D,char I)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		int res1,res2;
		res1=TOH(n-1,S,I,D);
			cout<<S<<"->"<<D<<endl;
		res2=TOH(n-1,I,D,S);
		return res1+res2+1;
	}
}
int main()
{
	int n;
	cout<<"\nEnter the number of disks = ";
	cin>>n;
	int res=TOH(n,'S','D','I');
	cout<<res<<" ";
	return 0;
}
