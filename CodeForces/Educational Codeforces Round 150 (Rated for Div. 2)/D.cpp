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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{int l,r;};
vector<node>v;
node p[maxn];
int n;
void solve()
{
	cin>>n;
	v.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i].l>>p[i].r;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int l=min(p[i].l,p[j].l);
			int r=max(p[i].r,p[j].r);
			if(r-l+1>=p[i].r-p[i].l+p[j].r-p[j].l+2)continue;
			v.push_back({l,r});
		}
	sort(v.begin(),v.end(),[&](auto a,auto b){
		if(a.r!=b.r)return a.r<b.r;
		return a.l<b.l;
	});
	int cnt=0;
	int r=-1;
	for(int i=0;i<v.size();i++)
		if(r<v[i].l)
			cnt++,r=v[i].r;
	cout<<n-2*cnt<<endl;
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