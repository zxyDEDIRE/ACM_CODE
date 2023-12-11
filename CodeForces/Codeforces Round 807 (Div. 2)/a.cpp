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
int p[maxn];
int n,k;
bool solve()
{
	cin>>n>>k;
	for(int i=1;i<=n*2;i++)
		cin>>p[i];
	sort(p+1,p+1+n*2);
	for(int i=1;i<=n;i++)
	{
		//cout<<p[i+n]<<" "<<p[i]<<endl;
		if(p[i+n]-p[i]<k)return 0;
	}
	return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){
    	if(solve())cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
    return 0;
}