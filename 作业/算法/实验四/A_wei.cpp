定义结构体node，包含id和dis两个成员变量
定义结构体Edge，包含to、next、w和val四个成员变量
定义数组edge、head、dis和vis
定义整数n、m、s和t

函数add(from, to, w, val)
    cnt = cnt + 1
    edge[cnt].w = w
    edge[cnt].val = val
    edge[cnt].to = to
    edge[cnt].next = head[from]
    head[from] = cnt

函数dij()
    for i from 1 to n
        dis[i] = INF
    dis[s] = 0
    vis.reset()

    定义优先队列q，并将{s,0}加入q

    while q不为空 do
        取出q的队首元素it并弹出队首元素
        x = it.id
        if vis[x]为true then continue

        vis[x] = true

        for i from head[x] to 不为0 do i=edge[i].next 
            y=edge[i].to;
            if dis[y]>dis[x]+edge[i].w then 
                dis[y]=dis[x]+edge[i].w;
                将{y,dis[y]}加入q

函数solve()
    while 输入n和m且n不为0 do 
        for i from 1 to n do 
            head[i]=0;
        cnt=0;
        for i from 1 to m do 
            输入x,y,w,v=0;
            add(x,y,w,v);
            add(y,x,w,v);
        
        s=1,t=n;
        dij();
        输出dis[t];