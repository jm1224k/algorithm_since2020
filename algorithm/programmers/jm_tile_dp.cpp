long long solution(int N) {
    
    long long tmp;
    long long n1 = 1, n2 = 1;
    
    if(N == 1) return 4;
    
    for(int i = 2; i <= N; i++, tmp = n1, n1 = n2, n2 += tmp);
    
    return (n1 * 2 + n2 * 2);
}
