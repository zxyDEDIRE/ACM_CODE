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
	std::vector<int> p,v;
	std::vector<int> a,b;
	cin>>n;
	p.resize(n);
	for(auto &i:p)
		cin>>i;
	sort(p.begin(),p.end());
	int len=0,fl=-1;
	for(auto i:p)
	{
		if(i==fl)len++;
		else fl=i,len=1;
		if(len<=2)
			v.push_back(i);
	}


	for(int i=0;i<v.size();i++)
		if(i&1)a.push_back(v[i]);
		else b.push_back(v[i]);
	int ans_1=1,ans_2=1;
	for(int i=1;i<a.size();i++)
		if(a[i]>a[i-1])ans_1++;
	for(int i=1;i<b.size();i++)
		if(b[i]>b[i-1])ans_2++;
	if(a.size()+b.size()==3)cout<<2<<endl;
	else
	cout<<min(ans_1,ans_2)<<endl;
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