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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e5;
int t[maxn][100],indx;
int num[maxn];
int n,m;
int get_num(char ch)
{
	if(ch>='A'&&ch<='Z')return ch-'A';
	else if(ch='a'&&ch<='z')return ch-'a'+26;
	else return ch-'0'+52;
}
void insert(string &str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			t[rt][c]=++indx;
		rt=t[rt][c];
	}
	num[rt]++;
}
int query(string &str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			return 0;
		rt=t[rt][c];
	}
	return num[rt];
	if(num[rt]==1)
	{
		num[rt]=2;
		return 1;
	}
	else if(num[rt]==2)return 2;
	else if(num[rt]==0)return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		insert(str);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		int x=query(str);
		if(x==1)cout<<"OK"<<endl;
		else if(x==2)cout<<"REPEAT"<<endl;
		else cout<<"WRONG"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}