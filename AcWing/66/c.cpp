/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int num[maxn];
int vis[maxn];
int p[maxn];
int n;
void NO(){
	cout<<"NO"<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		num[p[i]]++;
	}
	vector<int>v,q;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(num[p[i]]==1){
			cnt++;
			v.push_back(p[i]);
		}
		else q.push_back(p[i]);
	}
		
	if(cnt%2==0)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=cnt/2;i++)
			vis[v[i-1]]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[p[i]])cout<<'A';
			else cout<<'B';
		}
		cout<<endl;
	}
	else
	{
		int flag=-1;
		for(int i=0;i<q.size();i++)
			if(num[q[i]]>=3){
				flag=q[i];
				break;
			}
		if(flag==-1)return NO();
		cout<<"YES"<<endl;
		for(int i=1;i<=cnt/2;i++)
			vis[v[i-1]]=1;
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[p[i]])cout<<"A";
			else
			{
				if(p[i]==flag&&fl==0)cout<<"A",fl=1;
				else cout<<"B";
			}
		}
		cout<<endl;
	}

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
12
1 2 3 4  7 9 11
5 5 6 6 6
*/