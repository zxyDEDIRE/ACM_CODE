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
string str;
int a,b;
bool solve()
{
	cin>>a>>b>>str;
	int n=str.size();
	int l=0,r=n-1;
	while(l<r)
	{
		if(str[l]==str[r]&&str[l]!='?')
		{
			if(str[l]=='0')a-=2;
			else b-=2;
		}
		else if(str[l]==str[r]&&str[l]=='?')
		{
			if(a>=2)str[l]=str[r]='0',a-=2;
			else if(b>=2)str[l]=str[r]='1',b-=2;
			else return 0;
		}
		else if()
	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){
    	if(solve()==0)cout<<-1<<endl;
    }
    return 0;
}