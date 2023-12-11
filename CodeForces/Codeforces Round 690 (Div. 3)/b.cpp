#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string p;
int n;
void solve()
{
	cin>>n>>p;
	n--;
	string a;a=p[0];a+=p[1];a+=p[2];a+=p[3];
	string b;b=p[0];b+=p[1];b+=p[2];b+=p[n];
	string c;c=p[0];c+=p[1];c+=p[n-1];c+=p[n];
	string d;d=p[0];d+=p[n-2];d+=p[n-1];d+=p[n];
	string e;e=p[n-3];e+=p[n-2];e+=p[n-1];e+=p[n];
	string x="2020";
	if(a==x||b==x||c==x||d==x||e==x)cout<<"Yes"<<endl;
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