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
struct node{
	int x,y,z;
};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>mp(n+1,vector<int>(m+1,0));
	vector<int>cnt(n+1,0);
	vector<int>a,b;
	set<int>s[n+1];
	int num=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]==1)
				cnt[i]++,num++;
		}
	}
	if(num%n){
		cout<<-1<<endl;
		return ;
	}
	num/=n;
	// cout<<num<<endl;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>num)
		{
			a.push_back(i);
			for(int j=1;j<=m;j++)
				if(mp[i][j])
					s[i].insert(j);
		}
		else if(cnt[i]<num)
			b.push_back(i);
	}
	vector<node>ans;
	for(auto x:a)
	{
		for(int i:s[x])
		{
			if(cnt[x]==num)break;
			for(auto y:b)
			{
				if(cnt[y]==num)continue;
				else if(cnt[x]==num)break;
				else if(mp[y][i]!=1)
				{
					mp[y][i]=1;
					cnt[y]++;
					cnt[x]--;
					ans.push_back({x,y,i});
					break;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto [x,y,z]:ans)
		cout<<x<<" "<<y<<" "<<z<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 0 1 0 1 1 1 0 1 1
1 0 1 1 1 1 0 0 0 1
0 0 0 1 1 1 1 0 0 1
1 0 0 1 1 0 1 1 1 0
1 1 0 0 0 0 0 0 1 1
1 1 0 0 0 0 0 1 0 0
1 0 0 0 1 0 1 1 1 0
1 0 0 1 1 0 0 1 0 0
1 0 0 1 1 1 0 1 0 0
0 1 1 1 0 0 0 1 1 1
*/