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
int nxt[maxn];
char str[maxn];
int get_nxt(char *s)
{
	nxt[1]=0;
	map<int,int>mp;
	int n=strlen(s+1);
	int flag=1;
	int len=1;
	int ma=0;
	for(int i=2;i<=n;i++)
	{
		
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[nxt[i]+1]!=s[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
		if(i!=n)ma=max(ma,nxt[i]);
	}
	int x=nxt[n];
	while(x>ma)x=nxt[x];
	if(x==0)return -1;
	return x;
}
void solve()
{
	scanf("%s",str+1);
	int ans=get_nxt(str);
	if(ans==-1)printf("Just a legend\n");
	else
	{
		for(int i=1;i<=ans;i++)
			printf("%c",str[i]);
		printf("\n");
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\ \Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
aaakaaaakaaaaa
aaakaaaaa
aaaaa
qwertyqwertyqwertyqwertyqwertyqwerty
*/