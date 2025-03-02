#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    clock_t start, finish;
	start = clock();
    vector<int>v{-1};
    int n=1e6;
    // cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        v.insert(lower_bound(v.begin(),v.end(),x),x);
        int mid_l = ceil(1.0*i/3);
		int mid_r = ceil(2.0*i/3);
        cout<<v[mid_l]<<" "<<v[mid_r]<<"\n";
    }
    	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
    return 0;
}