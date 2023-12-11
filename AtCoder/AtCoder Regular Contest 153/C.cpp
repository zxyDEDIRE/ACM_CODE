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
const int maxn=1e6+100;
int p[maxn];
int a[maxn];
int b[maxn];
int n,fa,fb,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		b[i]=b[i+1]+a[i];
		if(b[i]<0)fa=1;
		if(b[i]>0)fb=1;
	}
	if(b[1]!=0)
	{
		cout<<"Yes"<<endl;
		for(int i=2;i<=n;i++)
			ans+=b[i]*abs(b[1]);
		ans/=b[1];p[1]=-ans;
		for(int i=2;i<=n;i++)p[i]=abs(b[1])+p[i-1];
		for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		cout<<endl;
	}
	else
	{
		if(!fa||!fb){
			cout<<"No"<<endl;return ;}
		cout<<"Yes"<<endl;
		int x=0;
		for(int i=2;i<=n;i++)x+=b[i];
		for(int i=n;i>=1;i--)
		{
			if(x>0&&b[i]==-1)p[i]=1+x,x=0;
			else if(x<0&&b[i]==1)p[i]=1-x,x=0;
			else p[i]=1;
		}
		for(int i=1;i<=n;i++)p[i]+=p[i-1];
		for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		cout<<endl;
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