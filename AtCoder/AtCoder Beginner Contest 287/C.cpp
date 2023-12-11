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
vector<int>v[maxn];
int in[maxn];
int n,m;
int p[maxn];
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	if(m!=n-1){
		cout<<"No"<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		in[x]++;
		in[y]++;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			p[fa]=fb;
		}
	} 
	int ans=0;
	int ans_1=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i)ans_1++;

		if(in[i]==1)ans++;
		else if(in[i]==0||in[i]>2){
			cout<<"No"<<endl;
			return ;
		}
	}
	if(ans==2&&ans_1==1)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
5 4
1 2
3 4
4 5
3 5
*/