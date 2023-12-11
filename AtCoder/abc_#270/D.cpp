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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int n;
int A(int m,int t)
{
	int a=0,b=0;
	int l=n;
	int flag=1;
	while(m)
	{
		while(m<p[l])l--;
		if(l-t>=0&&flag)
		{
			flag=0;
			a+=p[l-t],m-=p[l-t];
		}
		else
		{
			a+=p[l],m-=p[l];
		}
		
		while(m<p[l])l--;
		b+=p[l],m-=p[l];
	}
	return a;
}
void solve()
{
	int m;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	int ma=0;
	for(int i=0;i<=n;i++)
	{
		ma=max(ma,A(m,i));
	}
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
18 4
11 10 4 1
*/