/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
}b[maxn];
pii p[maxn];
int a[maxn];
bitset<10000>vis;
unordered_map<int,int>mp[600];
int n;
inline int dis(int &a,int &b){
	auto x=p[a],y=p[b];
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second,a[i]=i;
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)
			b[i].id=i,b[i].dis=dis(x,i);

		sort(b+1,b+1+n,[&](node a,node b){
			return a.dis<b.dis;
		});
		for(int i=1;i<=n;i++)
			a[i]=b[i].id;
		for(int l=1,r=1;l<=n;l++)
		{
			r=l;
			// mp.clear();
			while(r+1<=n&&dis(x,a[r+1])==dis(x,a[l]))r++;
			int num=r-l+1;
			if(num<2){
				l=r;
				continue;
			}
			vis.reset();
			mp[10].clear();vis[10]=1;
			mp[20].clear();vis[20]=1;
			int now=0;
			for(int i=l;i<=r;i++)
			{
				int k1=p[x].first-p[a[i]].first;
				int k2=p[x].second-p[a[i]].second;
				if(k1==0)mp[10][10]++;
				else if(k2==0)mp[20][20]++;
				else if(k1&&k2){
					int g=__gcd(k1,k2);
					k1/=g;k2/=g;
					if(k1<0)k1=-k1,k2=-k2;
					if(!vis[k1])vis[k1]=1,mp[k1].clear();
					mp[k1][k2]++;
				}
			}
			for(int i=l;i<=r;i++)
			{
				int k1=p[x].first-p[a[i]].first;
				int k2=p[x].second-p[a[i]].second;
				if(k1==0)now+=(num-mp[10][10]);
				else if(k2==0)now+=(num-mp[20][20]);
				else if(k1&&k2){
					int g=__gcd(k1,k2);
					k1/=g;k2/=g;
					if(k1<0)k1=-k1,k2=-k2;
					now+=(num-mp[k1][k2]);
				}
			}
			ans+=now/2;
			l=r;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// clock_t start, finish;
	// start = clock();
		solve();
	// 	finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}