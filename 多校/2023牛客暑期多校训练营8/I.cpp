#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const int INF=1e9+7;
const int mod=998244353;
const int maxn=1e6+100;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
{
	ext[0]=0;
	for(int i=1,p0=0,p=0;i<=lens;i++)
	{
		ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
		while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
		if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
	}
}
int nxt[maxn];
int ext[maxn];
int txt[maxn];
char s[maxn];
char t[maxn];
int m1,m2;
int n;
void solve()
{
	cin>>n>>s+1>>t+1;
	m1=strlen(s+1);
	m2=strlen(t+1);
	if((m1+m2)%2!=0){
		for(int i=1;i<=n;i++)
			cout<<"0 ";cout<<endl;
		return ;
	}
	if(m1==m2)
	{
		int flag=1;
		for(int i=1;i<=m1;i++)
			if(s[i]!=t[i]){flag=0;break;}
		for(int i=1;i<=n;i++)
			if(flag)cout<<ksm(26,i)<<" ";
			else cout<<"0 ";
	}
	else if(m1>m2)
	{
		int mid=(m1+m2)/2;
		int mi=0;
		for(int j=mid,i=m2;i>=1;i--,j--)
			if(s[j]!=t[i])mi=INF;
		exkmp(s,m1,s,m1,nxt,nxt);

		for(int i=1;i<=n;i++)
		{
			if(i<mi){cout<<"0 ";continue;}
			int _t=m1+i;
			int T=i*2+1+mid;

			int num=i+1-(m1-mid)-1;
			if(T<=_t)
			{
				if(nxt[T-i]<(m1-(T-i)+1)){cout<<"0 ";continue;}
				else cout<<1<<" ";
			}
			else cout<<ksm(26,max(0,num))<<" ";
		}
	}
	else if(m1<m2)
	{
		exkmp(s,m1,s,m1,nxt,nxt);
		exkmp(t,m2,s,m1,ext,nxt);
		exkmp(t,m2,t,m2,txt,txt);
		for(int i=1;i<=n;i++)
		{
			int t_1=i*2+m1+1;
			int tot=i*2+m1+m2;
			int mid=tot/2;
			if(t_1<=mid)
			{ 
				int t_2=t_1+mid-i*2-m1;
				if(txt[t_2]<(mid-t_1+1)){cout<<"0 ";continue;}
				int s_1=i+1;
				int T_1=t_1-mid;
				s_1-=(T_1-1);
				if(ext[s_1]<m1){cout<<"0 ";continue;}
				cout<<"1 ";
			}
			else
			{
				int s_1=i+1;
				int T_1=t_1-mid;
				s_1-=(T_1-1);
				if(ext[s_1]<m1){cout<<"0 ";continue;}
				cout<<ksm(26,t_1-mid-1)<<" ";
			}
		}
	}
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
1000
a
a

*/