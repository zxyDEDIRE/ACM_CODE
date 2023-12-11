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
int l[maxn],r[maxn];
int a[maxn];
int ans[maxn];
stack<int>s;
int n;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.y>y;
	}
}p[maxn];
priority_queue<node>q;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//q.push({i,a[i]});
		p[i]={i,a[i]};
	}
	for(int i=1;i<=n;i++){
		while(s.size()&&a[s.top()]>a[i]){
			r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		r[s.top()]=n+1;
		s.pop();
	}
	for(int i=n;i>=1;i--){
		while(s.size()&&a[s.top()]>a[i]){
			l[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		l[s.top()]=0;
		s.pop();
	}
	for(int i=1;i<=n;i++){
		l[i]+=1;
		r[i]-=1;
	}
	int fl=1;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.y>b.y;
	});
	for(int i=1;i<=n;i++)
	{
		auto [x,y]=p[i];
		int len=r[x]-l[x]+1;
		for(int j=fl;j<=len;j++)
		{
			ans[fl++]=y;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";

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