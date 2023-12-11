#include<bits/stdc++.h>
using namespace std;
int pre[2][1007];
void slov()
{
	string s;
	cin>>s;
	int n=s.size();
	for(int i=1;i<=n;i++)pre[0][i]=pre[1][i]=0;
	for(int i=1;i<=s.size();i++)
	{
		int num=s[i-1]-'0';
		pre[0][i]=pre[0][i-1];
		pre[1][i]=pre[1][i-1];
		pre[num][i]++;
	}
	int l1=s.find('1')+1,r1=s.rfind('1')+1;
	int l2=s.find('0')+1,r2=s.rfind('0')+1;
	
	int ans1=min(pre[0][n]-pre[0][l1],pre[0][r1]-pre[0][0]);
	int ans2=min(pre[1][n]-pre[1][l2],pre[1][r2]-pre[1][0]);
//	cout<<min(ans1,ans2)<<'\n';

	int mi=1e9;
	if(n==1)mi=0;
	for(int i=1;i<n;i++)
	{
		int ans1=pre[0][n]-pre[0][i+1]+pre[1][i]-pre[1][0];
		int ans2=pre[1][n]-pre[1][i+1]+pre[0][i]-pre[0][0];
		mi=min(ans1,mi);
		mi=min(ans2,mi);
	}
	cout<<mi<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		slov();
	}
}