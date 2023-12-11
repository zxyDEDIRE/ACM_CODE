/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
string str,res;
map<string,int>mp;
int n;
bool check(int mid)
{
	for(int i=0;i<(n-2*mid);i++)
	{
		string now=str.substr(i,mid);
		if(str.find(now,i+mid)!=string::npos){
			res=now;
			return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>str;
	n=str.size();
	int l=1,r=n,ans=1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(ans<n&&check(ans+1))ans++;
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5
TATCGATCGAGTTGT
TCCGCGAGCGAGTCTCTCCATT
GTTTCATCATACGAGGCCCCATACGCGCTGG
AGATGGGATCCTTATG
GCCCTTAGGCATGGGATGTCGTTTCTTG
*/