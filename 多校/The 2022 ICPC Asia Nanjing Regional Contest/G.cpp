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
int p[maxn];
int n;
void NO(){
	cout<<-1<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	deque<int>q;
	int sum=1,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==1)sum++,cnt++;
		else if(p[i]==0)q.push_back(i);
		else if(p[i]==-1)
		{
			if(cnt>1)cnt--;
			else if(q.size()){
				int x=q.front();q.pop_front();
				p[x]=1;
			}
			else return NO();
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" \n"[i==n];
	q.clear();
	sum=1,cnt=1;
	for(int i=1;i<=n;i++)
	{
		// cout<<"I "<<i<<" "<<p[i]<<endl;
		// cout<<sum<<" "<<cnt<<endl;
		if(p[i]==1)sum++,cnt++;
		else if(p[i]==-1)
		{
			cnt--;
			if(cnt==0)
			{
				int x=q.front();q.pop_front();
				cnt++;
				sum++,cnt++;
			}
		}
		else if(p[i]==0)
		{
			if(cnt>1)cnt--,q.push_back(i);
			else sum++,cnt++;
		}
		// cout<<sum<<" "<<cnt<<endl;
	}
	int g=__gcd(sum,cnt);
	sum/=g;
	cnt/=g;
	cout<<sum<<" "<<cnt<<endl;
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
1
8
1 0 0 0 -1 1 1 1


1 1
2 2 1
2 1 -1 0
3 2  1 0
3 1 -1 0
4 2 -1
5 3 1
6 4 1
7 5 1
*/