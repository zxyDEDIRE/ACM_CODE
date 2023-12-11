#include<bits/stdc++.h>
using namespace std;



int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int d = b - c;
  cout << ((a + d - 1) / d) << endl;

  cout<<ceil(a/(b-c))<<endl;
}