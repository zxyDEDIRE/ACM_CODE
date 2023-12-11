 const int N = 1e6 + 10 , M = 2 * N, INF = 0x3f3f3f3f;
 int n, m, k, x, a[N], b[N];
 int S, T;
 int primes[N], cnt;
 int st[N];
 int h[N], e[M], ne[M], idx;
 int dist[N];
 int pre[N];
 bool vis[N];
 void add(int a, int b) {
     e[idx] = b, ne[idx] = h[a], h[a] = idx++ ;
 }
 void init() {
     for (int i = 2; i < N; i++ ) {
         if (!st[i]) primes[cnt++] = i, st[i] = i;
         for (int j = 0; primes[j] * i < N; j++ ) {
             st[primes[j] * i] = primes[j];
             if (i % primes[j] == 0) break;
         }
     }
 }
 // 因为边权都是1，所以用bfs也是可以的。
 int dijkstra(int S, int T) {
     memset(dist, 0x3f, sizeof dist);
     memset(vis, 0, sizeof vis);
     priority_queue<PII, vector<PII>, greater<PII>> q;
     q.push({0, S});
     dist[S] = 0;
     while (q.size()) {
         auto t = q.top();
         q.pop();
         int ver = t.second;
         
         if (vis[ver]) continue;
         vis[ver] = true;
         for (int i = h[ver]; ~i; i = ne[i]) {
             int j = e[i];
             int w = 1;
             if (dist[j] > dist[ver] + w) {
                 dist[j] = dist[ver] + w;
                 pre[j] = ver;
                 q.push({dist[j], j});
             }
         }
     }
     if (dist[T] >= INF) return -1;
     return dist[T];
 }
 void solve()
 {
     cin >> n;
     memset(h, -1, sizeof h);
     for (int i = 1; i <= n; i++ ) cin >> a[i];
     cin >> S >> T;
     if (S == T) {
         cout << 1 << endl;
         cout << S << endl;
         return ;
     }
     if (a[S] == a[T]) {
         if (a[S] == 1) {
             cout << -1 << endl;
             return ;
         }
         cout << 2 << endl;
         cout << S << " " << T << endl;
         return ;
     }
     
     map<PII, int> mp;
     for (int i = 1; i <= n; i++ ) 
         for (int j = a[i]; j >= 2; j /= st[j]) {
             if (mp[{i, st[j]}]) continue;
             add(st[j] + n, i);
             add(i, st[j] + n);
             mp[{i, st[j]}] = 1;
         }
         
     int ans = dijkstra(S, T);
     if (ans == -1) cout << -1 << endl;
     else {
         vector<int> res;
         int cur = T;
         while(cur != S) {
             if(cur <= n) res.push_back(cur);
             cur = pre[cur];
         }
         res.push_back(S);
         cout << res.size() << endl; // 逆序输出答案
         for (int i = res.size() - 1; i >= 0; i-- ) cout << res[i] << " ";
     }
 }
 signed main()
 {
     ios::sync_with_stdio(0),cin.tie(0);
     init();
     // freopen("input.txt", "r", stdin);
     int T = 1;
     // cin >> T;
     while(T -- ) solve();
     please ac;
 }  