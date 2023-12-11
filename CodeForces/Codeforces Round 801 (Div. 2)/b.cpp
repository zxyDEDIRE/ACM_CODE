#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=100;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	ll mi=1e10,fl=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]<mi)
		{
			mi=p[i];
			fl=i;
		}
	}
	if(n&1){
		cout<<"Mike"<<endl;
		return ;
	}
	if(fl&1)cout<<"Joe"<<endl;
	else cout<<"Mike"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}