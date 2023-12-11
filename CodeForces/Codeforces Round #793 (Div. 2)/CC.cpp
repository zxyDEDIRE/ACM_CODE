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
	int n;
	vector<int>p,v,a,b;
	cin>>n;
	p.resize(n);
	for(auto &i:p)
		cin>>i;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	sort(p.begin(),p.end());
	int len=0,fl=-1;
	for(auto i:p)
	{
		if(i==fl)len++;
		else fl=i,len=1;
		if(len<=2)v.push_back(i);
	}
	for(int i=0;i<v.size();i++)
		if(i&1)a.push_back(v[i]);
		else b.push_back(v[i]);
	len=(int)(a.size()+b.size());
	v.resize(len);
	if(a.size()>=b.size())
	{
		for(int i=0,l=0;l<a.size();i+=2)
			v[i]=a[l++];
	}
	else
	{
		for(int i=1,l=0;l<a.size();i+=2)
			v[i]=a[l++];
	}

	if(b.size()>a.size())
	{
		for(int i=0,l=0;l<b.size();i+=2)
			v[i]=b[l++];
	}
	else
	{
		for(int i=1,l=0;l<b.size();i+=2)
			v[i]=b[l++];
	}
	


	int ans=min(a.size(),b.size());
	if(b.back()>a.back())ans=min(a.size()+1,b.size());
	if(a.back()>b.back())ans=min(a.size(),b.size()+1);
	if(a[0]<b[0])ans=min(a.size(),b.size()+1);
	if(a[0]>b[0])ans=min(a.size()+1,b.size());
	cout<<ans<<endl;
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
1 3 2 1 3

1 2 3 4 5
1 3 5 4 2

1 2 2 3
1 2 3 2
*/