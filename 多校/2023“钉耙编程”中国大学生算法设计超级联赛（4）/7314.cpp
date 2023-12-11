/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int num,id;
}p[maxn];
vector<int>v[maxn];
int b[maxn];
int a[maxn];
int n,indx;
void solve()
{
	cin>>n;
	int r=-INF;
	indx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		v[i].resize(b[i]);
		for(auto &x:v[i]){
			cin>>x;
			p[++indx]={x,i};
		}
		a[i]=1;
		sort(v[i].begin(),v[i].end());
		r=max(r,v[i][0]);
	}
	sort(p+1,p+1+indx,[&](node a,node b){return a.num<=b.num;});
	int ans=r-p[1].num;
	for(int i=1;i<=indx;i++)
	{
		auto [num,id]=p[i];
		ans=min(ans,r-num);
		if(a[id]<b[id])r=max(r,v[id][a[id]]),a[id]++;
		else break;
	}
	cout<<ans<<endl;
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