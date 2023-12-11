/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
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
	bool kmp(char *s,char *t)
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
				return 1;
				j=nxt[j];
			}
		}
		return 0;
	}
}kmp;
char ch[100][100];
char t[100];
int n;
bool check(int x,int l,int r)
{
	for(int i=l;i<=r;i++)
		t[i-l+1]=ch[x][i];
	t[r-l+2]='\0';
	kmp.init(t);
	for(int i=1;i<=n;i++)
	{
		if(!kmp.kmp(ch[i],t))
			return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ch[i]+1;
	for(int len=60;len>=3;len--)
	{
		set<string>s;
		for(int i=1;i<=n;i++)
		{
			int l=1,r=len;
			for(int j=1;j+len-1<=60;j++)
			{
				if(check(i,l,r))
				{
					string now="";
					for(int k=1;k<=len;k++)
						now=now+t[k];
					s.insert(now);
				}
				l++,r++;
			}
		}
		if(s.size()>0){
			cout<<*s.begin()<<endl;
			return ;
		}
	}
	cout<<"no significant commonalities"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
2
ACATCATCATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
ACATCATCATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
*/