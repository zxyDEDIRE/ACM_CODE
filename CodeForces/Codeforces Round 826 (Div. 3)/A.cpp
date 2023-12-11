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
void solve()
{
	string a,b;
	cin>>a>>b;
	int numa=0,numb=0;
	char fa,fb;
	for(auto i:a)
		if(i=='X')numa++;
		else fa=i;
	for(auto i:b)
		if(i=='X')numb++;
		else fb=i;
	if(fa==fb&&numa==numb)cout<<"="<<endl;
	else if(fa==fb)
	{
		if(fa=='S')
		{
			if(numa>numb)cout<<"<"<<endl;
			else cout<<">"<<endl;
		}
		else if(fa=='L')
		{
			if(numa<numb)cout<<"<"<<endl;
			else cout<<">"<<endl;
		}
	}
	else
	{
		if(fa=='L')cout<<">"<<endl;
		else if(fb=='L')cout<<"<"<<endl;
		else if(fa=='S')cout<<"<"<<endl;
		else if(fb=='S')cout<<">"<<endl;
	}
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