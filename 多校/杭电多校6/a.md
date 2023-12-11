Huah has n+kn+k cities numbered 1,2,.... ,n+k1,2,....,n+k, the city i(1\le i< n+k)i(1≤i<n+k) to the city i+1i+1 has n+k-in+k−i distinct one-way roads.

For each x=1,2,...,n-1x=1,2,...,n−1,the city i(x< i\le n+k)i(x<i≤n+k) to the city i-xi−x has a_xa 
x
​
  distinct one-way roads.

For m=k+1,k+2,... ,k+nm=k+1,k+2,...,k+n,find the number of paths from city k+1k+1 to city mm that pass through exactly kk number of roads.

Two paths are distinct when and only if the sequence of edges they pass through is distinct and the answer is modulo 998244353998244353.

Input
First line has one integer T(1\le T\le 14)T(1≤T≤14), indicating there are TT test cases. In each case:

First line input two integers n,k(2\le n\le 2\times 10^5,1\le k\le 2\times 10^5)n,k(2≤n≤2×10 
5
 ,1≤k≤2×10 
5
 ).

Second line n-1n−1 integers a_1,a_2,... ,a_{n-1}(0\le a_i\le 998244352)a 
1
​
 ,a 
2
​
 ,...,a 
n−1
​
 (0≤a 
i
​
 ≤998244352).

There is a blank line between case i(1\le i< T)i(1≤i<T) and case i+1i+1.

Input guarantee \sum (n+k) \le 1006769∑(n+k)≤1006769.

Output
In each case, output a row of nn integers with the ii-th integer being the answer when m=k+im=k+i.

Sample Input
4
3 2
1 2

3 1
1 2

5 10
2 3 3 3

3 3
166374059 748683265
Sample Output
5 0 2
0 2 0
114307026 825469567 425461680 73846080 5140800