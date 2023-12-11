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
string str;
int vis[40];
void solve()
{
	cin>>str;
	int fl=0;
	if(str.size()<26){
		cout<<-1<<endl;
		return ;
	}
	for(int i=0;i<str.size()-25;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=i+25;j++)
		{
			if(str[j]=='?')continue;
			int x=str[j]-'A'+1;
			vis[x]++;
		}
		int flag=1;
		for(int i=1;i<=26;i++)
			if(vis[i]>1)flag=0;
		if(flag)
		{
			fl=1;
			int s=1;
			for(int j=i;j<=i+25;j++)
			{
				if(str[j]=='?')
				{
					while(vis[s])s++;
					str[j]=(char)('A'+s-1);
					vis[s]=1;
				}
			}
		}
	}
	if(fl==0){
		cout<<-1<<endl;
		return ;
	}
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='?')cout<<"A";
		else cout<<str[i];
	}
	cout<<endl;

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
123
*/