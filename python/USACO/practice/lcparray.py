def calculate_lcp_array(s):
    n = len(s)
    rank = [0] * n
    height = [0] * n
    k = 0
    for i in range(n):
        if i == 0:
            continue
        if k > 0:
            k -= 1
        while (i + k < n) and (s[k] == s[i + k]):
            k += 1
        rank[i] = k
        if k == 0:
            continue
        for j in range(i + 1, n):
            if rank[j] < k:
                height[j] = k
            else:
                height[j] = height[j - i]
    return height
