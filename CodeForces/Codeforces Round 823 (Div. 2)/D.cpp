/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int mp[111][111];
string stra,strb;
int n;
void solve()
{
	cin>>n>>stra>>strb;
	memset(mp,0,sizeof(mp));
	stra=" "+stra;
	strb=" "+strb;
	for(int i=1;i<=n;i++)
	{
		int x=stra[i]-'a';
		int y=strb[n-i+1]-'a';

		if(x==y)mp[x][y]++;
		else
		{
			mp[x][y]++;
			mp[y][x]++;
		}	
	}

	if(n&1)
	{
		int x=stra[(n+1)/2]-'a';
		int y=strb[(n+1)/2]-'a';
		if(x==y&&(mp[x][y]&1))
		mp[x][y]++;
	}

	int flag=1;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(mp[i][j]&1){
				flag=0;
				cout<<i<<" "<<j<<endl;
			}
		}
	}

	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
abcaa
cbabb

ab
bb
ca
ab
ac
*/