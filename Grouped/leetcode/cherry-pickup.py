def ore_picks(G):
    N = len(G)
    dp = [[-1] * (N + 1) for _ in range(N + 1)]
    dp[0][0] = G[0][0]
    max_path = 2*N-1
    for x in range(1, max_path):
        start=min(N-1, x) 
        end=max(0, x-N+1)

        for a in range(start, end-1, -1):
            for b in range(start, a-1, -1):
                c, d = x-a, x-b
                if G[a][c]==-1 or G[b][d]==-1:
                    dp[a][b]=-1
                    continue
                
                if a==b: ct=G[a][c]
                else: ct=G[a][c]+G[b][d]

                max_prev = max(dp[a][b], dp[a][b-1], dp[a-1][b], dp[a-1][b-1])

                if max_prev!=-1: dp[a][b]=max_prev+ct
                else: dp[a][b]=-1

    return max(dp[N - 1][N - 1], 0)