#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int x,y;
void solve()
{
	cin>>x>>y;
	if((x+y)&1)cout<<-1<<" "<<-1<<endl;
	else
	{
		int len=x+y;
		len/=2;
		if(x>=len)cout<<x-len<<" "<<y<<endl;
		else cout<<x<<" "<<y-len<<endl;
	}

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
13 37
13 12

49 3
2 50
13 0
0 41
42 0
0 36
13 37
42 16
42 13
0 0
*/