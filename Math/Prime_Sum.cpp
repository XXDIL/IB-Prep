// making the Seive Array
vector<bool> generateSeiveArray(int n)
{
    vector<bool> Primes(n+1, 1);
    Primes[0] = Primes[1] = false;
    
    for(int i=2;i*i<=n;++i)
    {
        if(Primes[i])
        {
            for(int j=i*2;j<=n;j+=i)
                Primes[j] = 0;
        }
    }
    
    return Primes;
}

// really simple
vector<int> Solution::primesum(int A)
{
    vector<bool> Primes = generateSeiveArray(A);
    
    for(int i=2;i<=A;++i)
    {
        if(Primes[i] && Primes[A-i])
            return {i, A-i};
    }
    
    return {};
}
