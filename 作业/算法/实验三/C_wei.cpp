int dis array of size N x N
int n and m

function solve:
    input n and m
    for i from 1 to n:
        for j from 1 to n:
            if i != j:
                dis[i][j] = INF
    for i from 1 to m:
        input x, y and w
        dis[x][y] = dis[y][x] = w
    for k from 1 to n:
        for i from 1 to n:
            for j from 1 to n:
                dis[i][j] = minimum(dis[i][j], dis[i][k] + dis[k][j])
    output dis[1][n]