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
const int maxn=1e6;
int nxt[maxn];
int n;
void get_nxt(string &str)
{
	nxt[1]=0;
	for(int i=2;i<str.size();i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&str[nxt[i]+1]!=str[i])
			nxt[i]=nxt[nxt[i]];
		if(str[nxt[i]+1]==str[i])
			nxt[i]++;
	}
}
void solve()
{
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	for(int I=1;I<n;I++)
	{
		string t;
		cin>>t;
		t=" "+t;
		get_nxt(t);
		int n=s.size()-1;
		int m=t.size()-1;

		// cout<<"************"<<endl;
		// cout<<s<<" "<<t<<endl;
		// cout<<n<<" "<<m<<endl;

		int i=max(0,n-m-1);
		int j=0;
		for(;i<n;i++)
		{
			while(j&&t[j+1]!=s[i+1])
				j=nxt[j];
			if(t[j+1]==s[i+1])j++;
		}
		int len=j;
		for(int i=len+1;i<t.size();i++)
			s+=t[i];
		// cout<<"************"<<endl<<endl;
	}
	for(int i=1;i<s.size();i++)
		cout<<s[i];

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