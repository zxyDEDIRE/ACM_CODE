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
void solve()
{
	string str;
	vector<int>cnt(10,0);
	getline(cin,str);
	for(auto i:str)
	{
		int tmp=i-'0';
		if(tmp>=0&&tmp<=9)
		cnt[tmp]++;
	}
	int ma=-1,fl=0,flag=1;
	for(int i=0;i<=9;i++)
	{
		if(!cnt[i])
			flag=0;
		if(cnt[i]>ma)
		{
			ma=cnt[i];
			fl=i;
		}
	}
	cout<<fl<<" "<<ma<<endl;
	if(flag){
		cout<<"I Love GUES！"<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;getchar();
	while(__--)

		solve();
	return 0;
}