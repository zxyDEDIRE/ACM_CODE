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
int p[maxn],cnt;
int a[maxn];
int n,m;
void add(int x,int y){
	for(int i=1;i<=y;i++)
		p[++cnt]=x;
}
void solve()
{
	cin>>n>>m;
	cnt=0;
	if(n>m)swap(n,m);
	int _x=m/n;
	add(n,_x*n);

	queue<int>q;
	for(int i=1;i<=n;i++)
		a[i]=_x*n;
	for(int i=1;i<=m-_x*n;i++)
		q.push(n);
	int s=1;
	while(s!=n)
	{
		for(int i=s;i<=n;i++)
		{
			if(a[i]!=m)
			{
				int ned=m-a[i];
				int x=q.front();

				if(x>ned)
				{
					add(ned,1);
					a[i]=m;
					q.pop();
					q.push(x-ned);
				}
				else if(x<=ned)
				{
					add(x,1);
					q.pop();
					a[i]+=x;
				}
			}
			if(a[i]==m)s=i;
		}
	}


	sort(p+1,p+1+cnt,[&](int a,int b){return a>b;});
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<p[i]<<" \n"[i==cnt];
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4 6
4 4 4 4 2 2 2 2

4 7
4 4 4 4 3 1 3 1 3 1

10 6
6 6 6 6 6 6 6 6 6 6
*/