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
	void f(char *s,char *t)
	{
		vector<int>v;
		int len=strlen(s+1);
		int lenb=strlen(t+1);
		for(int i=0,j=0;i<len;i++)
		{
			while(j>0&&t[j+1]!=s[i+1])j=nxt[j];
			if(t[j+1]==s[i+1])j++;
			if(j==lenb)
			{
				v.push_back(i-lenb+2);
				j=nxt[j];
			}
		}
		if(v.size()==0){
			printf("Not Found\n\n");
			return ;
		}
		else
		{
			printf("%d\n",v.size());
			for(auto i:v)
				printf("%d ",i);
			printf("\n\n");
		}
	}
	void debug(){
		for (int i=0;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}kmp;
char s[maxn];
char t[maxn];
void solve()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	kmp.init(t);
	kmp.debug();
	// kmp.f(s,t);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}