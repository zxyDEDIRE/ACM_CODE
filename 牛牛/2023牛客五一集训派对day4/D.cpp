/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int _mi[maxn];
int _ma[maxn];
int p[maxn];
char s[maxn];
int n,ans=INF;
int f(int len)
{
	for(int i=1;i<=len;i++)
		_ma[i]=-1,_mi[i]=10;
	for(int i=1;i+len-1<=n;i+=len)
	{
		if(p[i]==0)return 111;
		int fa=0,fb=0;
		for(int j=1;j<=len;j++)
		{
			if(fa==0&&p[i+j-1]>_ma[j])fa=1;
			else if(fa==0&&p[i+j-1]<_ma[j])fa=-1;

			if(fb==0&&p[i+j-1]<_mi[j])fb=1;
			else if(fb==0&&p[i+j-1]>_mi[j])fb=-1;
		}
		if(fa==1){
			for(int j=1;j<=len;j++)
				_ma[j]=p[i+j-1];
		}
		if(fb==1){
			for(int j=1;j<=len;j++)
				_mi[j]=p[i+j-1];
		}
	}
	int now=0;
	for(int i=1;i<=len;i++){
		now=now*10+(_ma[i]-_mi[i]);
		if(now>1000)return 1111;
	}
	// cout<<"LEN "<<len<<" now "<<now<<endl;
	return now;
}
int h(int len)//991
{
	if(len*2>=n)return 1111;
	int _MI=999,_MA=-1;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==9)
		{
			if(i+len-1>n)return 111;
			for(int j=1;j<len;j++)
				if(p[i+j-1]!=9)return 1111;
			_MI=min(_MI,p[i+len-1]);
			_MA=max(_MA,p[i+len-1]);
			i=i+len-1;
		}
		else if(p[i]==1)
		{
			if(i+len>n)return 1111;
			for(int j=2;j<=len;j++)
				if(p[i+j-1]!=0)return 1111;
			_MI=min(_MI,10+p[i+len]);
			_MA=max(_MA,10+p[i+len]);
			i=i+len;
		}
		else if(len>1)return 111;
		else if(len==1)
		{
			_MI=min(_MI,p[i]);
			_MA=max(_MA,p[i]);
		}
	}
	// cout<<"H "<<len<<" now "<<_MA-_MI<<endl;
	return _MA-_MI;
}
void solve()
{
	cin>>n>>s+1;
	ans=INF;
	int _MA=0,_MI=9;
	for(int i=1;i<=n;i++)
	{
		p[i]=s[i]-'0';
		_MA=max(_MA,p[i]);
		_MI=min(_MI,p[i]);
	}
	p[n+1]=99999;
	ans=min(ans,_MA-_MI);
	for(int i=2;i*i<=n;i++)
		if(n%i==0){
			ans=min(ans,f(i));
			ans=min(ans,f(n/i));
		}
	int len=1;
	for(int i=1;i<=n;i++)
		if(p[i]==1){
			while(p[i+len]==0)len++;
			break;
		}
	// cout<<ans<<endl;
	// // cout<<"LEN "<<len<<endl;
	ans=min(ans,h(len+4));
	ans=min(ans,h(len+3));
	ans=min(ans,h(len+2));
	ans=min(ans,h(len+1));
	ans=min(ans,h(len));
	if(len>1)ans=min(ans,h(len-1));
	if(len>2)ans=min(ans,h(len-2));
	if(len>3)ans=min(ans,h(len-3));
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5
90929
*/