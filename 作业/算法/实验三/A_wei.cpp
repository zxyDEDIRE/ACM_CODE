function solve:
    input n and m
    for i from 1 to n:
        input w[i] and v[i]
    for i from 1 to n:
        for j from m to 0:
            if j >= w[i]:
                dp[j] = maximum(dp[j], dp[j-w[i]] + v[i])
    output dp[m]