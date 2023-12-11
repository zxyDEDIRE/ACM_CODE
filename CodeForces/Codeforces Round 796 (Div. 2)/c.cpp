#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int p[200];
int n;
void solve()
{
	cin>>n;
	memset(p,0,sizeof(p));
	n=n*2+1;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(auto j:str){
			p[j-'a']++;
		}
	}
	for(int i=0;i<100;i++)
		if(p[i]&1){
			cout<<(char)(i+'a')<<endl;
			return ;
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
a
ab
b
cd
acd
*/