#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int maxn=200;
string str;
int n;
void solve()
{
	cin>>n;
	cin>>str;
	char fl=str[0];
	int cnt=1,ans=0;
	int len=1;
	for(int i=1;i<n;i++){
		if(str[i]==fl){
			cnt++;
		}
		else{
			if(cnt%2==0)cnt=1,len++;
			else cnt=2,ans++,len++;
			fl=str[i];
		}
	}
	if(ans==0){
		cout<<0<<" "<<len<<"\n";
		return ;
	}

}
signed main(){
	int __;
	cin>>__;
	//__=1;
	while(__--)solve();
}
/*
1 2 3
1 1 3
0 1 3


*/