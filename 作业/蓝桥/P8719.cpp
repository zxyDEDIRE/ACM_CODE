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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string str="abcdefghijklmnopqrstuvwxyz";
string a;
int n;
bool cmp(char a,char b){return a>b;}
void solve()
{
	cin>>n;
	if(n>=325)a=a+str;
	if(n>=1300)a=a+str;
	if(n>=2925)a=a+str;
	if(n>=5200)a=a+str;
	if(n>=8125)a=a+str;
	for(int i=0;i<26;i++)
	{
		if(a.size()==0&&i==0)continue;
		if(i)a=a+(char)('a'+i-1);
		// cout<<a.size()<<endl;
		// cout<<a<<endl;
		sort(a.begin(),a.end());
		int m=n;
		for(int i=a.size()-1;i>0;i--)
		{
			for(int j=a.size()-1;j>=i;j--)
				if(a[j]>a[j-1]&&m){
					swap(a[j],a[j-1]);
					m--;
				}
		}
		if(m==0)
		{
			cout<<a<<endl;
			return ;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
jihgfeeddccbbaa
*/