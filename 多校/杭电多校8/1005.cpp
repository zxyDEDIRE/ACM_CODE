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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
int a[maxn];
int b[maxn];
int s[maxn];
int t[maxn];
int n,m;
int fs(int r){
	return s[r]=s[r]==r?s[r]:fs(s[r]);
}
int ft(int r){
	return t[r]=t[r]==r?t[r]:ft(t[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		s[i]=t[i]=i;

	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=2;j*j<=x;j++)
		{
			if(x%j!=0)continue;
			v[i].push_back(j);
			while(x%j==0)x/=j;
		}
		if(x>0)v[i].push_back(x);
	}
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		for(auto y:v[i])st.insert(y);
		if(st.count(b[i]))s[i]=s[i+1];
		else st.clear();
	}
	st.clear();
	for(int i=n;i>=1;i--)
	{
		for(auto y:v[i])st.insert(y);
		if(st.count(b[i-1]))t[i]=t[i-1];
		else st.clear();
	}
	cout<<"********************"<<endl;
	for(int i=1;i<=n;i++)
	{
		s[i]=fs(s[i]);
		cout<<s[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		t[i]=ft(t[i]);
		cout<<t[i]<<" ";
	}cout<<endl;
	cout<<"********************"<<endl;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		if(x<y)
		{
			int fa=fs(x);
			int fb=fs(y);
			if(fa==fb)cout<<"Yes"<<endl;
			else cout<<"no"<<endl;
		}
		else
		{
			int fa=ft(x);
			int fb=ft(y);
			if(fa==fb)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
7 1 6 6 14
7 2 3 2
*/