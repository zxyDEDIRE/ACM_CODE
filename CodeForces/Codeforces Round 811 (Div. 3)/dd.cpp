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
const int maxn=1e3;
map<string,int>mp;
bitset<maxn>vis;
bitset<maxn>ok;
vector<pii>v;
string str;
int n;
void solve()
{
	cin>>str>>n;
	vis.reset();
	mp.clear();
	ok.reset();
	v.clear();
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		mp[a]=i;
	}
	n=str.size();
	int i=0;
	while(1)
	{
		//cout<<i<<endl;
		if(i==n)break;
		if(i<0||ok[i]){
			cout<<-1<<endl;
			return ;
		}
		ok[i]=1;
		string x;
		string ans;
		int fl=0;
		for(int j=i,k=0;j<str.size(),k<=11;j++,k++)
		{
			x+=str[j];
			if(mp[x])ans=x,fl=mp[x];
		}
		if(fl)
		{
			v.push_back({fl,i+1});
			for(int j=0;j<ans.size();j++)
				vis[i+j]=1;
			i=i+ans.size();
		}
		else i-=1;
	}
	int flag=1;
	for(int i=0;i<str.size();i++)
		if(!vis[i])flag=0;
	if(flag==0)cout<<-1<<endl;
	else
	{
		cout<<v.size()<<endl;
		for(auto i:v)
			cout<<i.first<<" "<<i.second<<endl;
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
1
caba
2
bac
acab

aba
012
*/