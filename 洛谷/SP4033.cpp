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
const ull mod=212370440130137957ll;
const ull prime=233317;
const ull base=131;
const ull more=19260817;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<ull,bool>mp;
string p[maxn];
int n;
void solve()
{
	cin>>n;
	int flag=0;
	mp.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,[&](string a,string b){
		return a.size()<b.size();
	});
	for(int i=1;i<=n;i++)
	{
		string str=p[i];
		ull ans=0;
		for(int i=0;i<str.size();i++)
		{
			ans=(ans*base+(ull)(str[i]))%mod+prime;
			if(mp.count(ans))flag=1;
		}
		mp[ans]=1;
	}
	if(!flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
3
97625999
91125426
911
*/