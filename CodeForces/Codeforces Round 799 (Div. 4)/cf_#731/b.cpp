#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis;
string str;
char a;
void dfs(int s,int t,int x)
{
}
void solve()
{

	cin>>str;
	int s=-1;
	for(int i=0;i<str.size();i++)
		if(str[i]=='a'){
			s=i;break;
		}
	if(s==-1){
		cout<<"NO"<<endl;
		return ;
	}
	vis.reset();
	vis[s]=1;
	a='b';

	int l=s-1,r=s+1;
	while(1)
	{
		int flag=0;
		if(l>=0&&l<str.size()&&str[l]==a)l--,a++,flag=1;
		else if(r>=0&&r<str.size()&&str[r]==a)r++,a++,flag=1;
		if(!flag)break;
	}

	if(l==-1&&r==str.size())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

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