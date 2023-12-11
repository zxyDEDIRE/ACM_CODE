#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;
int a[N];
int n;
long long ksm(long long a,long long b){
    long long res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
map<int,bool>mp;
void solve(){
    int a,b;
    // cin>>a>>b;
     srand(time(0));
    a=rand();
    b=1e9+7;
    if(a<b) swap(a,b);
    if(mp[a-b]==true) {
        cout<<"1\n";
    }else{
        int cnt=a-b;
        for(int i=1;1ll*i*i<=cnt;i++){
            if(cnt%i==0){
                int a=i,b=cnt/i;
                if(a%2==b%2){
                    cout<<2<<'\n';return;
                }
            }
        }
        for(int i=1;1ll*i*i<=cnt;i++){
            if(mp[cnt-i*i]==true){
                cout<<2<<'\n';return;
            } 
         }
        cout<<min(3,cnt)<<'\n';
    }
}
/*
2
1 4
1 7
*/
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;1ll*i*i<=1e9;i++){
        mp[i*i]=true;
    }
    clock_t start, finish;
    start = clock();

    int t=1e5;
    // cin>>t;
    while(t--){
        solve();
    }
    finish = clock();
    cout << "the time cost is" <<\
    double(finish - start) / CLOCKS_PER_SEC;
    return 0;
}