#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	int X=0,Y=0,Z=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]&1)Y++;
		else {
			X++;
			for(int j=0;j<30;j++){
				if((1ll<<j)>p[i])break;
				if(j>Z)break;
				if((p[i]>>j)&1)
					Z=min(Z,j);
			}
		}
	}
	if(Y)cout<<X<<'\n';
	else cout<<X-1+Z<<'\n';
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
z
a
a
aa
yakumo
ran
yakumoran


1
1
2
3
4
34
*/