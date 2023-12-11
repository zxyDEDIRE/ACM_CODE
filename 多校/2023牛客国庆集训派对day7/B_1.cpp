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
	cout<<"cnt:"<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<p[i]<<" ";cout<<endl;
}
int b[maxn];
int ned[maxn];
int P[maxn];
int ans=INF;
int flag=0;
bool ok(int len,int x,int y)
{
	for(int i=1;i<=y;i++)
		ned[i]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=y;j++)
			if(ned[j]+b[i]<=x){
				ned[j]+=b[i];
				break;
			}
	}
	for(int i=1;i<=y;i++)
		if(ned[i]!=x)return 0;
	return 1;
}
void dfs(int step,int s,int sum)
{
	// cout<<step<<" "<<s<<" "<<sum<<endl;
	// for(int i=1;i<step;i++)
	// 	cout<<b[i]<<" ";cout<<endl;
	// cout<<endl;
	if(flag)return ;
	if(step>cnt+1)return ;
	if(step>ans+1)return ;
	if(sum==0)
	{
		if(!ok(step-1,n,m))return ;
		if(!ok(step-1,m,n))return ;
		ans=step-1;
		cout<<"ans:"<<ans<<endl;
		for(int i=1;i<=ans;i++){
			P[i]=b[i];
			cout<<b[i]<<" ";
		}
		cout<<endl;
		flag=1;
		return ;
	}
	for(int i=min(s,sum);i>=1;i--){
		b[step]=i;
		dfs(step+1,i,sum-i);
	}
}
void solve1()
{
	ans=INF;
	flag=0;
	dfs(1,n,n*m);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// cin>>n>>m;
	// if(n>m)swap(n,m);
	// 	solve();
	// 	solve1();

	while(1)
	{
		n=rand()%20+1;
		m=rand()%20+1;
		cout<<n<<" "<<m<<endl;
		if(n>m)swap(n,m);
		solve();
		solve1();
		int fl=1;
		if(ans!=cnt)fl=0;
		for(int i=1;i<=cnt;i++){
			if(p[i]!=P[i])fl=0;
		}
		if(!fl)break;
		_sleep(100);
	}


	return 0;
}