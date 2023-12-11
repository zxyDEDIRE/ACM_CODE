#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string s,t;
int n;
bool solve()
{
	cin>>n>>s>>t;
	vector<int>c,cc,a,aa;
	string x,y;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='b')x+=s[i];
		if(t[i]!='b')y+=t[i];

		if(s[i]=='a')a.push_back(i);
		if(t[i]=='a')aa.push_back(i);

		if(s[i]=='c')c.push_back(i);
		if(t[i]=='c')cc.push_back(i);
	}
	if(c.size()!=cc.size()||a.size()!=aa.size())return 0;
	for(int i=0;i<a.size();i++)
	{
		if(aa[i]<a[i])return 0;
	}
	for(int i=0;i<c.size();i++)
	{
		if(cc[i]>c[i])return 0;
	}
	if(x!=y)return 0;
	return 1;
}
int main(){
	vector<int>A,B;
	A.push_back(1);
	B.push_back(1);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){
    	if(solve())cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
    return 0;
}
//ab->ba
//bc->cb
/*
bcaabababc

cbbababaac

bcaabababc
cbbababaac

s里面的c在t里面c的后面
c在c的后面

aaaccaa
aaccaaa

3
abc
cab


s里面的a在t里面a的前面
s里面的c在t里面c的后面
s和t里面ac相对位置不变


*/