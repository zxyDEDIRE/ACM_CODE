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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n,k,m,fl,fr;
	cin>>n>>k;
	vector<int>p(n,0);
	for(int i=0;i<n;i++)
		cin>>p[i];
	fl=p[n-1];
	if(n-2>=0)fr=p[n-2];
	else fr=-1;

	sort(p.begin(),p.end());
	m = unique(p.begin(),p.end())-p.begin();

	for(int i=0;i<m;i++)
		cout<<p[i]<<" ";cout<<endl;

	int fl_x = lower_bound(p.begin(),p.begin()+m,fl)-p.begin();

	// cout<<k-m<<endl;
	cout<<"fl "<<fl<<endl;
	cout<<"fl_x "<<fl_x<<endl;
	if(fr!=-1&&fr<fl)
	{
		fr=(fr+1)%k;
		int fr_x=lower_bound(p.begin(),p.begin()+m,fr)-p.begin();
		cout<<"fr "<<fr<<endl;
		cout<<"fr_x "<<fr_x<<endl;
		if(p[fr_x]!=fr)
		{
			cout<<"Yes"<<endl;
			if(p[fl_x]-p[fr_x]+1==fl-fr)cout<<k-m-1<<endl;
			else cout<<k-m<<endl;
		}
		else cout<<k-m<<endl;
	}
	else cout<<k-m<<endl;
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
2
3 1
1 2 1
3 1
1 1 2
*/