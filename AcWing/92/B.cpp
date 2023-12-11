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
	int n,m=0;
	cin>>n;
	vector<int>v;
	string str;
	while(cin>>str){
		if(str=="int")v.push_back(1);
		else v.push_back(0),m++;
	}
	vector<vector<char>>mp(v.size());
	stack<pii>s;
	for(int tp=0;tp<v.size();tp++)
	{
		int i=v[tp];
		if(i==0)
			s.push({tp,0});
		else
		{
			s.push({tp,1});
			while(1)
			{
				if(s.size()<3)break;
				auto x=s.top();s.pop();
				auto y=s.top();s.pop();
				auto z=s.top();s.pop();
				if(x.second==1&&y.second==1&&z.second==0)
				{
					mp[z.first].push_back('<');
					mp[y.first].push_back(',');
					mp[x.first].push_back('>');
					s.push({x.first,1});
				}
				else{
					s.push(z);
					s.push(y);
					s.push(x);
					break;
				}
			}
		}
	}
	if(s.size()==1&&s.top().second==1);
	else {
		cout<<"Error occurred"<<endl;
		return ;
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==0)cout<<"pair";
		else cout<<"int";
		for(auto ch:mp[i])
			cout<<ch;
	}
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