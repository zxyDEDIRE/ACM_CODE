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
bitset<maxn>vis;
pii q[maxn];
int p[maxn];
int a[maxn];
int n,k;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int f(int x){
	if(x>n)return x-n;
	return x;
}
void un(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)
		p[fa]=fb;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n*3;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		int y=i+k-1;
		q[i]={x,y};
		cout<<"? ";
		for(int j=x;j<=y;j++)
			cout<<f(j)<<" ";
		cout<<endl;
		cin>>a[i];
		if(i>1)
		{
			int _x = q[i-1].first;_x=f(_x);
			int _y = q[i].second;_y=f(_y);
			if(a[i]==a[i-1])
			{
				un(_x,_y);
				un(_x+n,_y+n);
			}
			else
			{
				un(_x,_y+n);
				un(_x+n,_y);
			}
		}
	}
	int F=find(1);
	for(int i=1;i<=n;i++)
	{
		int fa=find(i);
		if(fa==F)vis[i]=1;
		else vis[i]=0;
	}
	int flag=0;
	int cnt_1=0;
	int cnt_2=0;
	for(int i=q[1].first;i<=q[1].second;i++)
		if(vis[f(i)])cnt_1++;
		else cnt_2++;

	if((a[1]%2)==(cnt_1%2))flag=1;
	else flag=0;

	cout<<"! ";
	for(int i=1;i<=n;i++)
		if(vis[i])cout<<flag<<" ";
		else cout<<(flag^1)<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10 5
0 1 0 1 1 1 0 1 0 0

1 2 3 4 5 6 7 8 9 10
1 2 3 4 5
1 2 3 4   6
1 2 3 4     7
1 2 3 4       8
1 2 3 4         9
1 2 3 4           10

*/