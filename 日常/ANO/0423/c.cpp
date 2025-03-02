#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n,a[200005];
void solve()
{
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=-1,r=-1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            l=i;
            break;
        }
    }
    for(int i=n;i>=2;i--){
        if(a[i]==a[i-1]){
            r=i;
            break;
        }
    }
    cout<<l<<" "<<r<<endl;
    if(n==2){
        cout<<0<<endl;
    }
    else if(l==-1){
        cout<<0<<endl;
    }
    else if(r-l==2)cout<<1<<endl;
    else cout<<r-l-2<<endl;
}
signed main()
{
	int __;
	cin>>__;
	//__=1;
	while(__--)solve();
}
