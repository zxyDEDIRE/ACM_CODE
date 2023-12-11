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
int dp[11100];
int p[maxn];
int n,sum=0;
int a,b;
void NO(){cout<<"NO"<<endl;}
void YES(){cout<<"YES"<<endl;}
void solve()
{
	cin>>n;
	a=b=sum=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x==2)a++;
		else b++;
		sum+=x;
	}
	if(sum%3!=0)return NO();
	if(sum&1)
	{
		if(b<3)return NO();
		sum-=9;
		b-=3;
	}
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(0);
	q.push(0);
	q.push(0);
	while(1)
	{
		int x=q.top();q.pop();
		if(b)x+=6,b-=2;
		else if(a)x+=2,a--;
		q.push(x);
		if(!a&&!b)break;
	}
	int x=q.top();q.pop();
	int y=q.top();q.pop();
	int z=q.top();q.pop();
	if(x==y&&y==z)return YES();
	else return NO();
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
1
4
2 2 2 3
*/