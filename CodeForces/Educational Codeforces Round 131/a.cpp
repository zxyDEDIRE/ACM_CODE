// /*
// 	嵌套变量是否相同
// 	特殊样例比如 0 1 2 n
// 	数组是否越界
// 	开long long
// */
// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// using pii=pair<int,int>;
// const int maxn=1e6;
// void solve()
// {
// 	int cnt=0;
// 	for(int i=1;i<=2;i++)
// 		for(int j=1;j<=2;j++){
// 			int x;cin>>x;
// 			if(x)cnt++;
// 		}
// 	if(cnt==0)cout<<0<<endl;
// 	else if(cnt==4)cout<<2<<endl;
// 	else cout<<1<<endl;
// }
// int main()
// {	
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);cout.tie(nullptr);
// 	int __;cin>>__;
// 	while(__--)
// 		solve();
// 	return 0;
// }
/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.x>x;
	}
};
void solve()
{
	set<pii>s;
	s.insert({1,1});
	s.insert({2,2});
	for(auto i:s)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}