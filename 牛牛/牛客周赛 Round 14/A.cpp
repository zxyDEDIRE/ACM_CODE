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
int n;
void solve()
{
	cin>>n;
	stack<char>s;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		if(s.size()&&s.top()==ch[i])
		{
			s.pop();
			ans++;
		}
		else s.push(ch[i]);
	}
	vector<char>v;
	while(s.size()){
		v.push_back(s.top());s.pop();
	}
	int l=0,r=v.size()-1;
	while(l<r)
	{
		if(v[l]==v[r])ans++;
		else break;
		l++,r--;
	}
	cout<<ans*2<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}