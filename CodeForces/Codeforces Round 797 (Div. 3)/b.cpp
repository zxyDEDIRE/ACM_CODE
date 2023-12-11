#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
int n;
bool solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    int ma=0;

    int cnt=-1;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>a[i])return 0;
        if(b[i]==0)pos=max(pos,a[i]);
        else{
            if(cnt==-1)cnt=a[i]-b[i];
            else {
                if(a[i]-b[i]!=cnt)return 0;
            }
        }
        if(cnt!=-1&&pos>cnt)return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){
        if(solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}