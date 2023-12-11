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
int p[maxn];
string str;
int n;
string solve()
{
	cin>>n>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+1+n,[&](int a,int b){
		if(str[a]==str[b])return a>b;
		return str[a]<str[b];
	});
	int l=1,r=n+1;
	for(int i=1;i<=n;i++)
	{
		while(l<=n&&(p[l]<i||p[l]>=r))l++;
		if(l<=n&&p[l]>i&&str[i]>str[p[l]]&&p[l]<=r)
		{
			r=p[l];
			swap(str[i],str[r]);
			l++;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<str[i];
	cout<<endl;
	string ans=str.substr(1,n);
	return ans;
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
7
euwsbfo
bswuefo
buswefo

1 5
2 4
*/