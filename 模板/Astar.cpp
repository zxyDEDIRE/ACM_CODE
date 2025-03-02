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
// 估计函数 对应数字之间的曼哈顿距离之和


int vx[]={-1,0,0,0,1,2,2,2,1};
int vy[]={-1,0,1,2,2,2,1,0,0};
string s,t="123804765";
int n;

int f_val(string now)
{
	int res = 0;
	for(int i=0;i<9;i++){
		int t=now[i]-'0';
		if(t)res += abs(i/3-vx[t]) + abs(i%3-vy[t]);
	}
	return res;
}
void solve()
{

	cin>>s;

	map<string,int>mp;
	priority_queue<pair<int,string>>q;
	q.push({-f_val(s),s});
	mp[s]=0;
	while(!q.empty())
	{
		auto [f,now]=q.top();q.pop();
		// cout<<now<<" "<<f<<endl;
		if(now==t){
			cout<<mp[now]<<endl;
			break;
		}
		int k=now.find('0');
		int x=k/3,y=k%3;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0||yy<0||xx >= 3||yy>=3)continue;
			string str=now;
			swap(str[k], str[xx*3+yy]);
			if(mp.count(str))continue;
			mp[str]=mp[now]+1;
			q.push({-(f_val(str)+mp[str]),str});
		}

	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}