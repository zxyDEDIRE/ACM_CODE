#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int sa,sb,t;
void solve()
{
	int cnt=0;
	int XX,YY,k;
	scanf("%d:%d%d",&XX,&YY,&k);
	int d=XX*60+YY;int x=XX*60+YY;
	int flag=0;
	while(1){	
		if(x==d&&flag)break;flag=1;XX=d/60;YY=d%60;d=(d+k)%1440;if(XX/10+10*(XX%10)==YY)cnt++;}
	cout<<cnt<<endl;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}