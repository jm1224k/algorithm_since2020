def solution(s):
    answer = 999999
    # 1. 자를 문자열 개수를 정한다 i : 2 ~ len(s) /2
    for sl in range(1,len(s)//2 +1):
        ret = ''
        cnt = 1
        prev = s[:sl]
        # 2. s를 순회하며 자른 문자열 개수를 비교하고 반복되는 것은 압축한다.
        for i in range(sl,len(s)+sl, sl):
            if prev == s[i:i+sl]:
                cnt += 1
            else:
                if cnt != 1:
                    ret = ret+str(cnt)+prev
                else:
                    ret = ret+prev
                prev = s[i:i+sl]
                cnt = 1
        answer = min(answer, len(ret))

    return min(answer, len(s))