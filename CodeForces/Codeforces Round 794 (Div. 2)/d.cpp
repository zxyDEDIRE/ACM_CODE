#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dp[maxn][3];
string str;
int a,b,c,d;
void solve()
{
	cin>>a>>b>>c>>d>>str;
	int A=0,B=0,x=0,y=0,z=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='A')A++;
		if(str[i]=='B')B++;
		if(str[i]=='A')
		{
			int fl=0;
			if(i>0&&str[i-1]==B )
		}
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
ababa
*/