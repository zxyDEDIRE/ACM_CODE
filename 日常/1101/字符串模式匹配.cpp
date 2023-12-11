#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;

char s[maxn];
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

void solve()
{

}
signed main(){
		solve();
	return 0;
}