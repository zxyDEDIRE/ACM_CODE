/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+200;
vector<int>v[maxn];
int in[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	if(n==1)
	{
		if(k)cout<<-1<<endl;
		else cout<<1<<endl;
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x=1;
		for(int j=1;i+x<=n&&cnt<k;j++)
		{
			// cout<<i+x<<" "<<i<<endl;
			v[i+x].push_back(i);
			in[i]++;
			cnt++;
			x*=2;
		}
		if(cnt==k)break;
	}
	if(cnt<k){cout<<-1<<endl;return ;}

	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		cout<<x<<" ";
		for(auto y:v[x])
		{
			in[y]--;
			if(in[y]==0)
				q.push(y);
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}