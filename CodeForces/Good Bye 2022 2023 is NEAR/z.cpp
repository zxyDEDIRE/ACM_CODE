#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define int long long
#define endl '\n'
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,m;
void solve()
{
    int num=0;
    cin>>n>>m;
    int r=n,l=1;
    while(1){
        for(int i=1;i<m;i++){
            cout<<r--<<" ";
            num++;
            if(num==n)break;
        }
        if(num==n)break;
        cout<<l++<<" ";
        num++;
        if(num==n)break;
    }
    cout<<endl;
}
signed main()
{
    //IOS
    int __=1;
    cin >> __;
    while (__--)
        solve();
}