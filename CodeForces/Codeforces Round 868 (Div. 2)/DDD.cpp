#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

const int N=200005;

int n,k,a[N],b[N];

void ldc(){
    cin >> n >> k;
    a[0]=b[0]=0;
    for(int i=1; i<=k; ++i) cin >> a[i];
    for(int i=1; i<=k; ++i) cin >> b[i];
    for(int i=0; i<k; ++i) if(b[i+1]-b[i]>a[i+1]-a[i]){
    	cout<<b[i+1]<<" "<<b[i]<<" "<<a[i+1]<<" "<<a[i]<<endl;
    	cout<<i<<endl;
        cout << "NO\n";
        return;
    }
    string res;
    int cur=-1,cur2=-1;
    for(int i=0; i<k; ++i){
        int cnt=b[i+1]-b[i];
        bool flag=0;
        for(int j=a[i]; j<a[i+1]; ++j){
            if(j<3){
                cur++;
                res+='a'+cur,cnt--;
            }
            else if(!flag&&b[i+1]-b[i]>0){
                cur++;
                res+='a'+cur,cnt--;
            }
            else if(cnt==0){
                cur2++;
                if(cur2==3) cur2=0;
                res+='a'+cur2;
            }
            else res+='a'+cur,cnt--;
            flag=1;
        }
    }
    cout << "YES\n" << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--) ldc();
}
/*
1
200 3
100 20
150 70
200 120

1
200 3
100 150 200
20 70 100
*/