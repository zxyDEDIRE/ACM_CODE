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
const int maxn=1e6;
struct QQ{int x,y,id;};
struct node{
	int x,dis;
	bitset<1510>ok;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
map<pair<bitset<1510>,int>,bool>mmp;
int d[maxn];
int men[maxn];
int mp[maxn];
vector<QQ>v;
int n,s,t;
void solve()
{
	cin>>n>>t;
	v.push_back({0,0,0});
	v.push_back({t,0,4});
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		v.push_back({x,i,1});
	}
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		v.push_back({x,i,2});
	}
	sort(v.begin(),v.end(),[&](QQ a,QQ b){
		return a.x<b.x;
	});
	for(int i=1;i<=n*2;i++)
	{
		d[i]=v[i-1].x;
		mp[i]=v[i-1].y;
		men[i]=v[i-1].id;
		if(v[i-1].id==0)s=i;
		if(v[i-1].id==4)t=i;
	}
	priority_queue<node>q;
	q.push({s,0,(0)});
	while(!q.empty())
	{
		auto [x,dis,vis]=q.top();q.pop();
		if(mmp[{vis,x}])continue;
		else mmp[{vis,x}]=1;
		if(x==t){
			cout<<dis<<endl;
			return ;
		}
		if(x>1)
		{
			if(men[x]==1)
			{
				
			}
			else if(men[x]==2)
			{

			}
		}
	}


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