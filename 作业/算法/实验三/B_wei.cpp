function solve:
    input n and m
    for i from 1 to n:
        for j from 1 to n:
            input mp[i][j]
    for i from 1 to n:
        for j from 1 to n:
            for k from 1 to n:
                mp[i][j] = mp[j][k] OR mp[i][k]