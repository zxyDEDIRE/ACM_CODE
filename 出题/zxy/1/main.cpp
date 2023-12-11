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
const int N=3111;
char mp[N][N];
int n;
void dfs(int x1,int y1,int x2,int y2,int op)
{
	if(x1==x2&&y1==y2){
		mp[x1][y1]=('0'+op);
		return ;
	}
	int mid_x=(x1+x2)>>1;
	int mid_y=(y1+y2)>>1;
	dfs(x1,y1,mid_x,mid_y,op);
	dfs(x1,mid_y+1,mid_x,y2,op^1);
	dfs(mid_x+1,y1,x2,mid_y,op^1);
	dfs(mid_x+1,mid_y+1,x2,y2,op);
}
void solve()
{
	cin>>n;
	n=(1ll<<n);
	dfs(1,1,n,n,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<mp[i][j];
		if(i!=n)
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

https://polygon.codeforces.com/plain-answer/answer-10.txt?testset=tests&index=10&session=e40d2be16baa1fbcac4ac4ce94a88eb0147bd4b7&ccid=1ea5ccabf3e3ad2d489fda4e0e37f208
https://dwz.cn/OwZR2vmA
*/