def matrix_chain_with_order(p):
    n = len(p) - 1  # NUMBER OF MATRICES
    dp = [[0]*n for _ in range(n)]  # MINIMUM COST TABLE
    s = [[0]*n for _ in range(n)]   # PARANTHESIS SPLIT TABLE
    # CHAIN LENGTH 2 TO N
    for length in range(2, n+1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1]
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    s[i][j] = k  # SPLIT POINT
    return dp, s

def print_order(s, i, j):
    if i == j:
        print(f"A{i+1}", end="")
    else:
        print("(", end="")
        print_order(s, i, s[i][j])       # LEFT
        print(" x ", end="")
        print_order(s, s[i][j]+1, j)     # RIGHT
        print(")", end="")

p = [10, 30, 5, 60]  # Dimensions: A1=10x30, A2=30x5, A3=5x60
dp, s = matrix_chain_with_order(p)
print("Minimum scalar multiplications:", dp[0][len(p)-2])
print("Optimal multiplication order:", end=" ")
print_order(s, 0, len(p)-2)
