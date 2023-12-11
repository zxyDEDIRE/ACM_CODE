#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
ll n;
void solve()
{
    cin>>n;
    if(n%3==0)
    {
        int a=n/3;
        cout<<a<<" "<<a+1<<" "<<a-1<<endl;
    }
    else if(n%3==1)
    {
        int a=n/3;
        cout<<a<<" "<<a+2<<" "<<a-1<<endl;
    }
    else if(n%3==2)
    {
        int a=n/3;
        cout<<a+1<<" "<<a+2<<" "<<a-1<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
3 4 4
*/