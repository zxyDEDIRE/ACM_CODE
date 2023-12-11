/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
int p[maxn];
int n,k;
int f(int n){
	if(n==1)return 1;
	int s=0,i=n-1,z=1;
	while(0<=i)
	{
		s+=i;
		i-=z;
		z+=z;
	}
	return s;
}
void solve()
{
	cin>>n>>k;
	int num=f(n);
	if(k>num){cout<<-1<<endl;return ;}

	int i=n;
	while(num>k)
	{
		int x=1;
		for(int j=1;i-x>0&&num>k;j++)
		{
			num--;
			v[i-x].push_back(i);
			in[i]++;
			x*=2;
		}
		i--;
	}
	queue<int>q;
	for(int i=n;i>=1;i--)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		cout<<x<<" ";
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
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