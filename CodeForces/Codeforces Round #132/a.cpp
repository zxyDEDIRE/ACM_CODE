/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[10];
void solve()
{
	int n,a,b,c;
	cin>>n>>p[1]>>p[2]>>p[3];

	n=p[n];
	if(n==0){
		cout<<"No"<<endl;
		return ;
	}
	n=p[n];if(n==0){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}