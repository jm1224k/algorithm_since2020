def solution(left, right):
    l_len = len(left)
    r_len = len(right)

    arr = [[0 for _ in range(l_len+1)]for _ in range(r_len+1)]

    for i in range(r_len):
        for j in range(l_len):
            l,r = left[j], right[i]
            if l > r:
                arr[i][j] = arr[i-1][j] + right[i]
            else:
                a = arr[i - 1][j - 1]
                b = arr[i][j - 1]
                arr[i][j] = max(arr[i-1][j-1],arr[i][j-1])
    return arr[r_len-1][l_len-1]
