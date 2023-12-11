/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[40],G[40];
string a,b;
int cnt[maxn];
int p[maxn];
int n;
void NO(){cout<<-1<<endl;}
int find(int r){
	return p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>a>>b;
	for(int i=1;i<=30;i++)
		p[i]=i,G[i].clear();
	for(int i=0;i<n;i++)
	{
		int x=a[i]-'a'+1;
		int y=b[i]-'a'+1;
		if(y<x)return NO();
		G[y].push_back(x);
	}
	int cnt=0;
	for(int i=1;i<=26;i++)
	{
		for(auto y:G[i])
		{
			int fa=find(i);
			int fb=find(y);
			if(fa!=fb)
			{
				cnt++;
				p[fb]=fa;
			}
		}
	}
	cout<<cnt<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}