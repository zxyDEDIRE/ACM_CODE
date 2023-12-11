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
string str;
int a[maxn];
int p[maxn];
int q[maxn];

int n,m,k;
int s,t,mid;
ll sum;
int f(int x,int len)
{
	ll _sum=sum;
	_sum-=abs(x-p[s+1]);
	int fa=lower_bound(p+2+s,p+1+t,x+len)-p;
	if(fa!=t+1)
		_sum-=(t-fa+1);
	_sum+=p[t+1]-(x+len-1);
	if(_sum<sum)return _sum;
	else return -1;
}
bool check(int len)
{
	sum=0;
	s=0,t=0,mid=1;
	for(int i=1;i<=len;i++)
		sum+=p[i]-i;
	while(p[mid]<mid)mid++;
	if(sum<=k)return 1;
	t=len;
	for(int i=1;i+len-1<=n;i++)
	{
		while(1)
		{
			if(t==m)break;
			int nxt=f(i,len);
			if(nxt!=-1)
				sum=nxt,s++,t++;
			else break;
		}
		// t-s==len
		if(sum<=k)return 1;
		cout<<i<<" "<<s<<" "<<t<<" "<<sum<<endl;

		int fa=lower_bound(p+s+1,p+1+t,i+len-1)-p;
		if(fa==t+1)
			sum+=len;
		else if(fa==1&&p[s+1]>i+len-1)
			sum-=len;
		else
		{
			if(p[fa]==i+len-1)
			{
				sum+=fa;
				sum-=len-fa;
			}
			else
			{
				sum+=fa-1;
				sum-=len-fa+1;
			}
		}



		cout<<i+1<<" "<<s<<" "<<t<<" "<<sum<<endl;
		cout<<endl;
	}
	return 0;
}
void solve()
{
	cin>>n>>k>>str;
	for(int i=1;i<=n;i++){
		if(str[i-1]-'0'==6)
			p[++m]=i;
	}
	// int l=1,r=m,ans=1;
	// while(l<r-1)
	// {
	// 	int mid=(l+r)>>1;
	// 	if(check(mid))ans=mid,l=mid;
	// 	else r=mid;
	// }
	// while(ans<n&&check(ans+1))ans++;
	// cout<<ans<<endl;
	cout<<check(3)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
11 3
66669999666
*/
/*
i i+len-1


1~i 之间+1
i+len~n 之间-1

5
6 6 9 9 6 6 9 9 6 9 6

p:
0 1 2 3 4 5 6
0 1 2 5 6 9 11

i=1:
	s=0,t=5
	sum=0+0+2+2+4=8
	s=0,t=5,sum8

i=2
	s=0,t=5;

	  6 9 9 6 6
	6 6 9 9 6



*/