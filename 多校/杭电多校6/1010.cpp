// /*
//     嵌套变量重复
//     特殊样例 0 1 2 n
//     数组越界
//     开long long
// */
// #include<bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// using ll=long long;
// using pii=pair<int,int>;
// const int INF=0x3f3f3f3f;
// const int maxn=1e6;
// pii a[maxn];
// int p[maxn];
// int n,m;
// int find(int r){
// 	return p[r]=p[r]==r?p[r]:find(p[r]);
// }
// void solve()
// {
// 	cin>>n>>m;
// 	vector<int>v;
// 	for(int i=1;i<=n;i++)
// 		p[i]=i;
// 	for(int i=1;i<=m;i++)
// 		cin>>a[i].first>>a[i].second;
// 	for(int i=1;i<=m;i++)
// 	{
// 		int x,y;
// 		int fa=find(a[i].first);
// 		int fb=find(a[i].second);
// 		if(fa==fb){
// 			v.push_back(i);
// 		}
// 		else p[fa]=fb;
// 	}
// 	if(v.size())
// 	{
// 		cout<<v.size()<<endl;
// 		//reverse(v.begin(),v.end());
// 		for(auto i:v)
// 			cout<<i<<" ";
// 		cout<<endl;

// 	}
// 	else cout<<"0\n\n";
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
//     int __;cin>>__;
//     while(__--)
//         solve();
//     return 0;
// }
/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define 日你妈退钱 void
#define 输出 cout<<
#define 输出结束 <<endl;
#define 循环 for
#define 解决 solve
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
日你妈退钱 解决()
{
	int n=10;
	循环(int i=1;i<=n;i++)
		输出 i 输出结束
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}