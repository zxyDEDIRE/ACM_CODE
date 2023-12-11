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
int dp[maxn][2];
int p[maxn];
int n;
int Get_Min(int *p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			if(p[(i+k)%n]>p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
void solve()
{
	int tmp;
	cin>>n;
	vector<int>a,b,vis;
	for(int i=0;i<n;i++)
		cin>>p[i];
	tmp=Get_Min(p,n);
	for(int i=0;i<n;i++){
		if(a.size()!=0&&p[(i+tmp)%n]==a.back())
			vis[vis.size()-1]=1;
		if(a.size()==0||p[(i+tmp)%n]!=a.back())
			a.push_back(p[(i+tmp)%n]),vis.push_back(0);
	}
	for(int i=0;i<n;i++)
		cin>>p[i];
	tmp=Get_Min(p,n);
	for(int i=0;i<n;i++)
		if(b.size()==0||p[(i+tmp)%n]!=b.back())
			b.push_back(p[(i+tmp)%n]);
	vector<int>v[n+1];
	for(int i=0;i<b.size();i++){
		v[b[i]].push_back(i);
	}
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" "<<vis[i]<<endl;

	cout<<endl;
	for(int i=0;i<b.size();i++)
		cout<<b[i]<<" ";
	cout<<endl;


	dp[0][0]=1;
	for(int i=0;i<a.size();i++)
	{
		for(auto j:v[a[i]])
		{
			if(!dp[j-1][0])break;
			if(vis[i]){
				dp[j][0]=dp[j][1]|=dp[j-1][0];
			}
			else
			{
				dp[j][1]|=dp[j-1][1];
				dp[j][0]|=dp[j-1][0];
			}
		}
	}
	if(dp[b.size()-1][1])
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 1 2 2 3 3
2 2 3 3 1 1
1 2 3
2 3 1


2 3 1
2 1
*/