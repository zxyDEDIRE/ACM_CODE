/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n*2;i++)
		p[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y)||find(x+n)==find(y+n))
			ans=1;
		else
		{
			p[find(x)]=find(y+n);
			p[find(y)]=find(x+n);
		}
	}
	if(ans)cout<<"Suspicious bugs found!"<<endl;
	else cout<<"No suspicious bugs found!"<<endl;
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Scenario #"<<i<<":"<<endl;
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}