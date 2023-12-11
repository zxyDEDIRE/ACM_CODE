/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=0;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		v[i%k].push_back(p[i]);
	}
	vector<int>q;
	for(int i=0;i<k;i++)
		for(auto x:v[i])
			if((x%k)!=i){
				// cout<<x<<endl;
				q.push_back(i);
			}
	if(q.size()==0)cout<<0<<endl;
	else if(q.size()==2)cout<<1<<endl;
	else cout<<-1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 1 4 2
4 2 3 1



*/