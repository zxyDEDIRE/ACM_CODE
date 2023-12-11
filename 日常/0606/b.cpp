#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	stack<char>s;
	string str;
	int ans=0;

	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		char ch=str[i];
		if(s.empty()||ch!=s.top())s.push(ch);
		else
		{
			ans++;
			s.pop();
		}
	}
	if(ans&1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}