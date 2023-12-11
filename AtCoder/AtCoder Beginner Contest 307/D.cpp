/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
int vis[maxn];
string str,ans;
int n;
void solve()
{
	cin>>n>>str;
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		char ch=str[i];
		if(ch==')'){
			if(s.size())
			{
				vis[s.top()]=1;
				vis[i]=-1;
				s.pop();
			}
		}
		else if(ch=='(')s.push(i);
	}
	int flag=0;
	// for(int i=0;i<n;i++)
	// 	cout<<vis[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(flag==0)
		{
			if(vis[i]==1)flag++;
			else cout<<str[i];
		}
		else if(flag)
		{
			if(vis[i]==-1)flag--;
			else if(vis[i]==1)flag++;
		}
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}