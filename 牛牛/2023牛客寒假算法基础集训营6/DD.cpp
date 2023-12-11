/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e5+100;
int a[maxn][4];
int b[maxn][4];
string str;
int n;
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=0;i<n;i++)
	{
		if(i>0){
			a[i][0]=a[i-1][0];
			a[i][1]=a[i-1][1];
			a[i][2]=a[i-1][2];
		}
		
		if(str[i]=='d')
			a[i][1]+=a[i][0];
		else if(str[i]=='u')
			a[i][2]+=a[i][1],a[i][0]++;
	}
	for(int i=n-1;i>=0;i--)
	{
		b[i][0]=b[i+1][0];
		b[i][1]=b[i+1][1];
		b[i][2]=b[i+1][2];
		if(str[i]=='d')
			b[i][1]+=b[i][0];
		else if(str[i]=='u')
			b[i][2]+=b[i][1],b[i][0]++;
	}
	int ma=0,fl=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='u')
		{
			if(ma<a[i][1]+b[i][1])
			{
				ma=a[i][1]+b[i][1];
				fl=i;
			}
		}
		else if(str[i]=='d')
		{
			if(ma<a[i][0]*b[i][0])
			{
				ma=a[i][0]*b[i][0];
				fl=i;
			}
		}
	}
	str[fl]='a';
	cout<<str<<endl;
	// cout<<a[1][1]<<endl;
	// cout<<b[1][1]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
udu
*/