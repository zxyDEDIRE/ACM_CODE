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
string str,ans;
int n,k;
void solve()
{
	cin>>n>>k>>str;
	ans=str[0];
	int indx=0;
	for(int i=1;i<n;i++)
	{
		if(str[i]>ans[indx]){
			break;
		}
		ans+=str[i];
		if(str[i]==ans[indx])indx++;
		else indx=0;
	}
	while(indx!=0){
		ans.pop_back();
		indx--;
	}
	int len=ans.size();
	for(int i=0;i<k;i++)
		cout<<ans[i%len];cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}