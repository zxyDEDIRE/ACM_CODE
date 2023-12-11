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
int p[maxn];
int flag=1,fa=0;
int n;
void solve()
{
	cin>>n;
	flag=1,fa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i>1&&p[i]!=p[i-1])
			flag=0;
		if(i>1&&p[i]==p[i-1])
			fa=1;
	}
	if(p[1]==p[n])fa=1;
	if(flag){
		cout<<1<<endl;
		for(int i=1;i<=n;i++)
			cout<<1<<" ";
		cout<<endl;
	}
	else if(n%2==0)
	{
		cout<<2<<endl;
		for(int i=1;i<=n;i++){
			if(i&1)cout<<1<<" ";
			else cout<<2<<" ";
		}
		cout<<endl;
	}
	else if(fa)
	{
		cout<<2<<endl;
		int cnt=0;
		int nxt=0;
		for(int i=1;i<=n;i++)
		{
			if(i==1)nxt=cnt%2+1,cout<<cnt%2+1<<" ",cnt++;
			else if(fa&&p[i]==p[i-1])
				cout<<nxt<<" ",fa=0;
			else nxt=cnt%2+1,cout<<cnt%2+1<<" ",cnt++;
		}
		cout<<endl;
	}
	else
	{
		cout<<3<<endl;
		for(int i=1;i<n;i++){
			if(i&1)cout<<1<<" ";
			else cout<<2<<" ";
		}
		cout<<3<<endl;
	}
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