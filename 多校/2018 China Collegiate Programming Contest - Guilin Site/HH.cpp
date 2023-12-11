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
vector<int>v;
string s,t;
char f(int x)
{
	for(char j='a';;j++)
	{
		if(s[x]==j)continue;
		if(t[x]==j)continue;
		return j;
	}
}
void solve()
{
	cin>>s>>t;
	int a=0,b=0;
	string str;
	int n=s.size();
	v.clear();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')a++;
		if(t[i]=='a')b++;
		str+='a';
	}
	int aa=min(a,b);
	a-=aa;
	b-=aa;
	if(a>b)swap(s,t);
	a=max(a,b);
	int flag=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==t[i])continue;
		if(a)
		{
			if(t[i]=='a')
			{
				if(a>=2)str[i]=s[i],a-=2;
				else if(a==1)
				{
					flag=1;
					str[i]=f(i);
					a--;
				}
				v.push_back(i);
			}
			else 
			{
				str[i]=s[i];
				if(s[i]=='a')v.push_back(i);
				else a--,v.push_back(i);
			}
		}
	}
	sort(v.begin(),v.end());
	for(auto i:v)
	{
		if(flag)
		{
			char x=s[i];
			char t=f(i);
			if(t<x)str[i]=t,flag=0;
			else str[i]=x;
		}
		else str[i]=s[i];
	}
	if(flag)
	{
		int x=v.back();
		str[x]=f(x);
	}
	cout<<str<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<": ";
		// cout<<endl;
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

aaaab
bbbba
*/