/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=2e6;
struct KMP{
	int nxt[maxn];
	int len;
	void init(char *s)
	{
		nxt[1]=0;
		len=strlen(s+1);
		for(int i=2;i<=len;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i])
				nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
		}
	}
	void kmp(char *s,char *t)
	{
		int lens=strlen(s+1);
		int lent=strlen(t+1);
		int cnt=0;
		for(int i=0,j=0;i<lens;i++)
		{
			while(j&&s[i+1]!=t[j+1])j=nxt[j];
			if(s[i+1]==t[j+1])j++;
			if(j==lent)
			{
				cnt++;
				j=nxt[j];
			}
		}
	}
	/* 循环周期 形如 acaca 中 ac 是一个合法周期 */
	vector<int> periodic()
	{
		vector<int>ret;
		int now=len;
		while(now)
		{
			now=nxt[now];
			ret.push_back(len-now);
		}
		return ret;
	}
	/* 循环节 形如 acac 中ac、acac是循环节，aca不是*/
	void periodic_loop()
	{
		vector<int>ret= periodic();
		if(len%ret[0]==0)cout<<len/ret[0]<<endl;
		else cout<<1<<endl;
	}
	void debug(){
		for (int i=0;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}kmp;
char s[maxn];
string str;
int n;
void solve()
{
	for(int i=0;i<str.size();i++)
		s[i+1]=str[i];
	s[str.size()+1]='\0';
	kmp.init(s);
	kmp.periodic_loop();
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin>>str){
    	if(str==".")break;
        solve();
    }
    return 0;
}
/*
aaaaaabaaaaaaa
*/