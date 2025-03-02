/*
注意由于要求以i结尾，所以串长两两不等，这里的回文子串个数即为本质不同回文子串个数
给定一个字符串 s。保证每个字符为小写字母。对于 s 的每个位置，请求出以该位置结尾的回文子串个数。
具体地，若第 i(i>=11)个位置的答案是k，第 i+1 个字符读入时的ASCII码为c，
则第i+1个字符实际的ASCII码为(c-97+k)mod26+97。所有字符在加密前后都为小写字母。
*/
#include<bits/stdc++.h>
using namespace std; 

const int N = 2e6 + 5; 
struct PAM_Trie
{
	int ch[26]; 
	int fail, len, num; 
}; 
struct PAM
{
	PAM_Trie b[N]; 
	int n, length, last, cnt, s[N]; 
	char c[N]; 
	
	PAM()
	{
		b[0].len = 0; b[1].len = -1; 
		b[0].fail = 1; b[1].fail = 0; 
		last = 0; 
		cnt = 1; 
	}
	void read()
	{
		scanf("%s", c + 1); 
		length = strlen(c + 1); 
	}
	int get_fail(int x)
	{
		while(s[n - b[x].len - 1] != s[n])
		{
			//printf("%d %d %d\n", x, n - b[x].len - 1, b[x].fail); 
			x = b[x].fail; 
		}
		return x; 
	}
	void insert()
	{
		int p = get_fail(last); 
		if(!b[p].ch[s[n]])
		{
			b[++cnt].len = b[p].len + 2; 
			int tmp = get_fail(b[p].fail); 
			b[cnt].fail = b[tmp].ch[s[n]]; 
			b[cnt].num = b[b[cnt].fail].num + 1; 
			b[p].ch[s[n]] = cnt; 
		}
		last = b[p].ch[s[n]]; 
	}
	void solve()
	{
		int k = 0; 
		s[0] = 26; 
		for(n = 1; n <= length; n++)
		{
			c[n] = (c[n] - 97 + k) % 26 + 97; 
			s[n] = c[n] - 'a'; 
			insert(); 
			printf("%d ", b[last].num); 
			k = b[last].num; 
		}
	}
}P; 
signed main()
{
	P.read(); 
	P.solve(); 
	return 0; 
}