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
const int maxn=1e6+100;
int p[maxn];
int n;
bool solve(int n)
{
	cin>>n;
	if(n%2==0){
		cout<<"No"<<endl;
		return 0;
	}
	ll sum=1ll*(1+n+n)*(n+n)/2;
	ll sum_2=1ll*(n+1+n+n)*n/2;
	ll no=sum_2/n;
	int indx = (1+n+n)-sum_2/n;
	cout<<"indx "<<indx<<endl;
	for(int i=indx,j=1;i>=1;i--,j++)
		p[i]=j;
	for(int i=indx+1,j=n;i<=n;i++,j--)
		p[i]=j;
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++){
		cout<<p[i]<<" "<<(i+no-p[i])<<endl;
	}
	// 100000 00000





	return 1;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i+=1){
		int fl=solve(i);
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 3 4 5 6

1 2 3 4 5
6 7 8 9 10
7 9 11 13 15
8 9 10 11 12
1 2 3 4 5 6 7
8 9 10 11 12 13 14
*/