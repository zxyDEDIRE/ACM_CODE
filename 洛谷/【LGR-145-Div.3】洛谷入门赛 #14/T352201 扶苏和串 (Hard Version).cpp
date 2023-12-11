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
string str;
string ans;
void solve()
{
	cin>>str;
	// for(int i=1;i<=3000;i++)
	// 	if(i&1)str=str+'1';
	// 	else str=str+'0';
	int n=str.size();
	ans=str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')continue;
		int cnt=0;
		int ma=0;
		for(int j=i+1;j<n;j++)
		{
			if(str[j]=='1')cnt=0;
			else cnt++;
			ma=max(ma,cnt);
		}
		cnt=0;
		for(int j=i+1;j<n;j++)
		{
			if(str[j]=='1')cnt=0;
			else cnt++;

			if(cnt==ma)
			{
				string a=str.substr(0,i);
				string b=str.substr(i,(j-i+1));
				string c=str.substr(j+1,(n-j-1));
				reverse(b.begin(),b.end());
				string now=a+b+c;
				ans=min(ans,now);	
			}
		}
		break;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// 	clock_t start, finish;
	// start = clock();
	/*******代码*******/
	solve();
	/****************/
	// finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0011101001
01234
 ...
/home/zhnag/App/Clash\ for\ Windows-0.20.25-x64-linux
*/