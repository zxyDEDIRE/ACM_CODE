/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int in[maxn];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i,in[i]=1;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		cnt++;
		if(fa!=fb)
		{
			cnt--;
			if(in[fa]>=in[fb])
			{
				p[fb]=fa;
				in[fa]+=in[fb];
			}
			else
			{
				p[fa]=fb;
				in[fb]+=in[fa];
			}
		}
		vector<int>v;
		for(int j=1;j<=n;j++)
			if(find(j)==j)
				v.push_back(in[j]);
		sort(v.begin(),v.end(),[&](int a,int b){
			return a>b;
		});
		int ans=0;
		for(int j=0;j<=min(cnt,(int)v.size()-1);j++)
			ans+=v[j];
		cout<<ans-1<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}