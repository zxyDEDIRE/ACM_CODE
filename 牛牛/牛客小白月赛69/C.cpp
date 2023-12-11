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
struct node{
	int a,b,c,x,y;
}P[111];
int id[111];
int n,t,p;
void solve()
{
	cin>>n>>t>>p;
	for(int i=1;i<=n;i++){
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		P[i]={a,b,c,x,y};
		id[i]=i;
	}
	int ma=0;
	do{
		int now=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			auto [a,b,c,x,y]=P[id[i]];
			if(now+x>t)break;
			x=now+x;
			ans+=max(c,a-x*b-y*p);
			now=x;
		}
		ma=max(ma,ans);
	}while(next_permutation(id+1,id+1+n));
	cout<<ma<<endl;
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