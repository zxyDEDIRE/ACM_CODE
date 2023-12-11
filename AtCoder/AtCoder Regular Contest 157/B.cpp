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
void solve()
{
	int n,k;
	string str;
	vector<pii>v;

	cin>>n>>k>>str;
	str=" "+str;
	int cnt_x=0;
	for(auto i:str)
		if(i=='X')cnt_x++;
	if(k>cnt_x)
	{
		k=n-k;
		cnt_x=n-cnt_x;
		for(int i=1;i<=n;i++)
			if(str[i]=='Y')str[i]='X';
			else str[i]='Y';
	}
	if(cnt_x==n){
		cout<<max(0,k-1)<<endl;
		return ;
	}

	int l=-1;
	int L,R;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='Y')
		{
			if(l==-1)l=i;
			else
			{
				v.push_back({l,i});
				l=i;
			}
		}
	}
	if(v.size()){
		L=v[0].first;
		R=v.back().second;
	}else{
		L=l;
		R=l;
	}
	
	sort(v.begin(),v.end(),[&](pii a,pii b){
		int x=a.second-a.first;
		int y=b.second-b.first;
		if(x!=y)return x<y;
		else return a.second<b.second;
	});
	for(auto [l,r]:v)
	{
		for(int i=l+1;i<r;i++)
			if(k)str[i]='Y',k--;
		if(!k)break;
	}
	for(int i=L-1;i>=1;i--)
		if(k)str[i]='Y',k--;
		else break;
	for(int i=R+1;i<=n;i++)
		if(k)str[i]='Y',k--;
		else break;
	int ans=0;
	for(int i=2;i<=n;i++)
		if(str[i-1]=='Y'&&str[i]=='Y')
			ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
XYXYX

1
YYYYY
*/