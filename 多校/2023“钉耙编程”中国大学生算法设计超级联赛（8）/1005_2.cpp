/*！*/
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
char ch[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	ch[0]=ch[n+1]='a';
	for(int i=1;i<=n;i++)
		cin>>ch[i],a[i]=0;
	for(int i=0;i<=n+1;i++)a[i]=b[i]=0;
	for(int i=1;i<=n;i++)
		if(ch[i]!=ch[i-1])a[i]=1;
		else a[i]=a[i-1]+1;
	for(int i=n;i>=1;i--)
		if(ch[i]!=ch[i+1])b[i]=1;
		else b[i]=b[i+1]+1;
	int l=1,r=n,op=0;
	while(1)
	{
		if(l>r){cout<<-1<<endl;return ;}
		else if(ch[l]==ch[r]&&ch[l]-'0'!=op){cout<<(op^1)<<endl;return ;}	

		if(ch[l]!=ch[r]&&ch[l]-'0'==op)l++;
		else if(ch[l]!=ch[r]&&ch[r]-'0'==op)r--;
		else if(l+1<=r&&ch[l]==ch[l+1]&&ch[l]-'0'==op)l++;
		else if(r-1>=l&&ch[r-1]==ch[r]&&ch[r]-'0'==op)r--;
		else if(l+1<=r&&ch[l]!=ch[l+1]&&b[l+1]>1)r--;
		else if(r-1>=l&&ch[r-1]!=ch[r]&&a[r-1]>1)l++;
		else l++;
		op^=1;
	}
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);

	// int m;
	// cin>>m;
	// for(int len=1;len<=m;len++)
	// {
	// 	for(int i=0;i<(1<<len);i++)
	// 	{
	// 		for(int j=1;j<=len;j++)
	// 			if(i&(1<<(j-1)))
	// 				ch[j]='1';
	// 			else ch[j]='0';
	// 		n=m;
	// 		for(int j=1;j<=len;j++)
	// 			cout<<ch[j];
	// 		cout<<" ";
	// 		solve();
	// 	}
	// }
	int __;cin>>__;
	while(__--)
		solve();

//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7
1001000
*/