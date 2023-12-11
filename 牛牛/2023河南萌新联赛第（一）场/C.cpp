#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 10;

string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k >> s;

    int cnt = 0;
    for(int i = 1; i < n; i ++){
        if(s[i] != s[i - 1]) cnt ++;
    }

    if(cnt == 0) cout << "Bob\n";
    else if(cnt >= 4) cout << ":(\n";
    else{
        if(cnt == 1){
            int sum = 0;
            for(int i=0;i<n;i++)
                if(s[i]==s[0])sum++;
            sum=min(sum, n-sum); 
            if(sum <= k) cout << "Alice\n";
            else if(s=="1100"||s=="0011") cout << "Bob\n";
            else cout << ":(\n";
        }
        else if(cnt == 2){
            int sum = 0;
            for(int i = 0; i < n; i ++)
                if(s[i]!=s[0]) sum ++;
            if(sum <= k)cout << "Alice\n";
            else if(s=="1001"||s=="0110")cout<<"Bob\n";
            else cout<<":(\n";
        }
        else if(cnt == 3){
            if(s == "1010" || s == "0101") cout << "Bob\n";
            else cout << ":(\n";
        }
    }
    return 0;
}
/*
10100

110011
1001

1100
0011
*/