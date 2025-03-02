#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
char mp[maxn][maxn];
struct node{char ch;int x;char fl;};
vector<node>v;
int xa[maxn][30];
int ya[maxn][30];
bool vis[maxn<<2];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='?')continue;
			int t=mp[i][j]-'a';
			xa[i][t]++;
			ya[j][t]++;
		}
	}
	queue<int>q;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=0;j<26;j++)
			if(xa[i][j])cnt++;
		if(cnt==1)q.push(i),flag=1;
	}
	if(!flag)
	{
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int j=0;j<26;j++)
				if(ya[i][j])cnt++;
			if(cnt==1)q.push(i+n);
		}
	}

	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		int ch;
		if(x<=n)
		{
			for(int i=0;i<26;i++)
				if(xa[x][i])ch=i;
			v.push_back(node{'h',x,(char)(ch+'a')});
			for(int i=1;i<=n;i++)
			{
				if(vis[i+n])continue;
				int t=mp[x][i]-'a';
				if(t==ch)ya[i][t]--;
			}
			for(int i=1;i<=n;i++)
			{
				int cnt=0;
				for(int j=0;j<26;j++)
					if(ya[i][j])cnt++;
				if(cnt==1)q.push(i+n);
			}
		}
		else
		{
			for(int i=0;i<26;i++)
				if(ya[x-n][i])ch=i;
			v.push_back(node{'v',x-n,(char)(ch+'a')});
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				int t=mp[i][x-n]-'a';
				if(t==ch)xa[i][t]--;
			}
			for(int i=1;i<=n;i++)
			{
				int cnt=0;
				for(int j=0;j<26;j++){
					if(xa[i][j])cnt++;
			//		cout<<xa[i][j];
				}
			//	cout<<endl;
				if(cnt==1)q.push(i);
			}
		}
	}

	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i].ch<<" "<<v[i].x<<" "<<v[i].fl<<endl;
}
/*
acz
abz
acz

??a
c??
caa

caa
ccc
caa
*/