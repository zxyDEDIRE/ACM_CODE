#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>v[maxn];
int q[maxn];
int n,m;
bool cmp(vector<pii>a,vector<pii>b)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].first==b[i].first)continue;
		else return a[i].first<b[i].first;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=m;i++)v[i].clear(),q[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1,x;j<=m;j++)
		{
			cin>>x;
			v[j].push_back(pii(x,j));
		}
	}
	sort(v+1,v+1+m,cmp);
	vector<pii>p;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(v[j][i].first>v[j+1][i].first){
				cout<<-1<<endl;
				return ;
			}
		}
	}
	
	/*
	for(int i=1;i<=m;i++)
		cout<<v[i][0].second<<" ";
	cout<<endl;*/

	int fl=0,flag=0;
	for(int i=1;i<=m;i++)
	{
		int x=v[i][0].second;
		if(x!=i)
		{
			if(fl<=1)
			{
				fl++;
				int y=v[x][0].second;
				if(y!=i){
					flag=1;
				}
				else p.push_back(pii(i,x));
			}
			else flag=1;
		}
	}
	if(flag)cout<<-1<<endl;
	else if(p.size())cout<<p[0].first<<" "<<p[0].second<<endl;
	else cout<<1<<" "<<1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
5

2 3
1 2 3
1 1 1

2 2
4 1
2 3

2 2
2 1
1 1

2 3
6 2 1
5 4 3

2 1
1
2

*/