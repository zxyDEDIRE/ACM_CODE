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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	vector<int>v[3];
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,[&](int a,int b){
		return a>b;
	});
	for(int i=1;i<=n;i++)
	{
		sum+=p[i];
		v[p[i]%3].push_back(p[i]);
	}
	int yu=sum%3;
	if(yu==1)
	{
		if(v[1].size())v[1].pop_back();
		else v[2].pop_back(),v[2].pop_back();
	}
	else if(yu==2)
	{
		if(v[2].size())v[2].pop_back();
		else v[1].pop_back(),v[1].pop_back();
	}
	vector<int>ans;
	for(auto i:v[0])
		ans.push_back(i);
	for(auto i:v[1])
		ans.push_back(i);
	for(auto i:v[2])
		ans.push_back(i);
	sort(ans.begin(),ans.end(),[&](int a,int b){
		return a>b;
	});
	if(ans.size()==0||ans[0]==0){
		cout<<-1<<endl;
	}
	else
	{
		for(auto i:ans)
			cout<<i;cout<<endl;
	}

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}