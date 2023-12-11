#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
struct node{char ch;int x;char fl;};
char mp[maxn][maxn];
int xa[maxn][30];
int ya[maxn][30];
vector<node>v;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			int t=mp[i][j]-'a';
			if(t<0)continue;
			xa[i][t]++;
			ya[j][t]++;
		}
		queue<int>q;
		int flag=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=0;j<26;j++)
				if(xa[i][j])cnt++;
			if(cnt==1)q.push(i),flag=1;
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++){
				int cnt=0;
				for(int j=0;j<26;j++)
					if(ya[i][j])cnt++;
				if(cnt==1)q.push(i+n),flag=1;
			}
		}




		cout<<q.size();
	}