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
char ch[10];
void solve()
{
	for(int i=1;i<=4;i++)
		cin>>ch[i];
	sort(ch+1,ch+1+4);
	vector<int>v;
	int s=1;
	for(int i=2;i<=4;i++)
	{
		if(ch[i]!=ch[i-1])v.push_back(s),s=1;
		else s++;
	}
	v.push_back(s);
	sort(v.begin(),v.end());
	int ans=0;
	cout<<v.size()-1<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}