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
vector<int>v[5];
vector<int>s;
int p[1111];
bool doit()
{
	int flag=0;
	vector<pii>back;
	for(auto i:s)
	{
		if(i<v[1].back()&&v[1].back()-i==10)back.push_back({i,1});
		if(i<v[2].back()&&v[2].back()-i==10)back.push_back({i,2});
		if(i>v[3].back()&&i-v[3].back()==10)back.push_back({i,3});
		if(i>v[4].back()&&i-v[4].back()==10)back.push_back({i,4});
	}
	if(back.size())
	{
		auto [x,id]=back[0];
		v[id].push_back(x);
		s.erase(find(s.begin(),s.end(),x));
		flag=1;
	}
	else
	{
		int mi=INF;
		for(auto i:s)
		{
			if(i>v[1].back())mi=min(mi,i-v[1].back());
			if(i>v[2].back())mi=min(mi,i-v[2].back());
			if(i<v[3].back())mi=min(mi,v[3].back()-i);
			if(i<v[4].back())mi=min(mi,v[4].back()-i);
		}
		vector<pii>ok;
		for(auto i:s)
		{
			if(i>v[1].back()&&i-v[1].back()==mi)ok.push_back({i,1});
			if(i>v[2].back()&&i-v[2].back()==mi)ok.push_back({i,2});
			if(i<v[3].back()&&v[3].back()-i==mi)ok.push_back({i,3});
			if(i<v[4].back()&&v[4].back()-i==mi)ok.push_back({i,4});
		}
		if(ok.size())
		{
			flag=1;
			auto [x,id]=ok[0];
			v[id].push_back(x);
			s.erase(find(s.begin(),s.end(),x));
		}
	}
	return flag;
}
void solve()
{
	for(int i=1;i<=98;i++)
		cin>>p[i];
	
	for(int j=1;j<=8;j++)
		s.push_back(p[j]);
	v[1].push_back(1);
	v[2].push_back(1);
	v[3].push_back(100);
	v[4].push_back(100);
	int t=8;
	int fl=1;
	while(1)
	{
		int flag_1=1;
		for(int tmp=1;tmp<=2;tmp++)
		{
			int fl=doit();
			if(fl==0){
				flag_1=0;
				break;
			}
		}
		if(!flag_1){
			fl=0;
			break;
		}
		if(t==98)break;
		s.push_back(p[++t]);
		s.push_back(p[++t]);
	}
	while(fl&&doit());
	for(int i=1;i<=4;i++)
	{
		for(auto j:v[i])
			cout<<j<<" ";
		cout<<endl;
	}
	for(auto i:s)
		cout<<i<<" ";
	cout<<endl;
	for(t=t+1;t<=98;t++)
		cout<<p[t]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
