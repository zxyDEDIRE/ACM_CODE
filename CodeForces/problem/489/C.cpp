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
int a[maxn],b[maxn];
void A(int n,int m)
{
	a[1]=1;
	int i=n;
	m--;
	while(m)
	{
		int x=9-a[i];
		if(x>=m)a[i]+=m,m=0;
		else a[i]=9,m-=x;
		i--;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<" ";
}
void B(int n,int m)
{
	int i=1;
	while(m)
	{
		if(m<9)b[i]=m,m=0;
		else b[i]=9,m-=9;
		i++;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i];
	cout<<" ";
}
void solve()
{
	int n,m;
	cin>>n>>m;
	if((m==0&&n!=1)||9*n<m)cout<<"-1 -1"<<endl;
	else{
		A(n,m);
		B(n,m);
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