/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,a,b;
void solve()
{
	cin>>n>>m>>a>>b;
	int ans=0;
	for(int i=0;i<4;i++)
	{
		int x=a+dx[i];
		int y=b+dy[i];
		if(x<1||y<1||x>n||y>m)continue;
		ans++;
	}
	cout<<ans<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}