#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=111;
struct node{int a,b,c,d;};
int mp[maxn][maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&mp[i][j]);
	vector<node>v;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(mp[i][j])
			{
				if(i>1)v.push_back({i-1,j,i,j});
				else if(j>1)v.push_back({i,j-1,i,j});
				else{
					cout<<"-1"<<endl;
					return ;
				}
			}
		}
	}
	cout<<v.size()<<endl;
	if(v.size()==0)return ;
	for(int i=0;i<v.size();i++)
		cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].d<<"\n";

}
int main(){
	int __;cin>>__;
	while(__--)solve();
}