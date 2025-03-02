#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll x,y;
void solve()
{
	cin>>x>>y;
	if(x<y)swap(x,y);
	if(x>2*y)cout<<y<<endl;
	else cout<<(x+y)/3<<endl;
}
int main(){
    cout<<"的发送"<<endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
2 1
1 2
*/