/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
// using ull=unsigned long long;
// using ll=long long;
// using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pair<int,int>p[maxn];
int a[maxn];
int n,m,s;
bool cmp(int a,int b){
	return a>b;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=m;i++){
		cin>>p[i].first>>p[i].second;
	}
	vector<pair<int,int> >v;
	v.push_back(make_pair(1,1));
	for(int i=1;i<=m;i++)
	{
		pair<int,int>&now =v.back();
		int &x=now.first;
		int &y=now.second;
		int a=p[i].first;
		int b=p[i].second;
		if(a==x&&a==0)y=max(y,b);
		else if(a==x&&a==1)y=min(y,b);
		else v.push_back(make_pair(a,b));
	}
	int s=1;
	for(int i=1;i<v.size();i++)
	{
		int op=v[i].first;
		int x=v[i].second;
		if(op==0)
		{
			if(x<=s)continue;
			else sort(a+s,a+1+x,cmp),s=x;
		}
		else
		{
			if(x>=s)continue;
			else sort(a+x,a+s+1),s=x;
		}
		// cout<<op<<" "<<x<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\input1.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
 // fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 3
0 2
0 4
0 1


*/