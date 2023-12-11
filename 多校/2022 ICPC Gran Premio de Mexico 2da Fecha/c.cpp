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
vector<int>v[maxn];
vector<int>u[maxn];
map<int,int>a[maxn];
map<int,int>mp,pm;
int cnt;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,num;
		cin>>x>>num;
		if(!mp.count(x))mp[x]=cnt++;
		while(num--)
		{
			int y;
			cin>>y;
			v[mp[x]].push_back(y);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,num;
		cin>>x>>num;
		if(!mp.count(x))mp[x]=cnt++;
		while(num--)
		{
			int y;
			cin>>y;
			u[mp[x]].push_back(y);
		}
	}
	vector<int>id;
	for(auto [X,x]:mp){
		id.push_back(X);
	}
	sort(id.begin(),id.end());
	int wanzh=1;
	int renshu=0;
	int duo=0;
	int shao=0;
	for(int o=0;o<id.size();o++)
	{
		int x=mp[id[o]];
		sort(v[x].begin(),v[x].end());
		sort(u[x].begin(),u[x].end());
		if(v[x]!=u[x])
		{
			renshu++;
			// for(auto i:v[x])
			// 	cout<<i<<" ";cout<<endl;
			// for(auto i:u[x])
			// 	cout<<i<<" ";cout<<endl;
			wanzh=0;
			cout<<id[o]<<" ";
			int i=0,j=0;
			while(1)
			{
				if(i==v[x].size()&&j==u[x].size())break;
				else if(i==v[x].size()&&j!=u[x].size())cout<<"-"<<u[x][j]<<" ",j++,duo++;
				else if(i!=v[x].size()&&j==u[x].size())cout<<"+"<<v[x][i]<<" ",i++,shao++;
				else if(v[x][i]==u[x][j])i++,j++;
				else if(v[x][i]<u[x][j])cout<<"+"<<v[x][i]<<" ",i++,shao++;
				else if(v[x][i]>u[x][j])cout<<"-"<<u[x][j]<<" ",j++,duo++;
			}
			cout<<endl;
		}
	}
	if(wanzh)cout<<"GREAT WORK! NO MISTAKES FOUND!"<<endl;
	else cout<<"MISTAKES IN "<<renshu<<" STUDENTS: "<<duo<<" NOT REQUESTED, "<<shao<<" MISSED"<<endl;
}
//MISTAKES IN 7 STUDENTS: 14 NOT REQUESTED, 4 MISSED
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
/*
1 1
1 2 3 4
1 3 3 4 5
*/