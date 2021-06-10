/* store the products into a set */
int Solution::colorful(int A)
{
    string num = to_string(A);
    int n = num.size();
    unordered_set<int> S;

    for(int i=0;i<n;++i)
    {
        int prod = 1;
        for(int j=i;j<n;++j)
        {
            prod *= int(num[j] - '0');

            if(S.find(prod) != S.end())
                return 0;
            S.insert(prod);
        }
    }

    return 1;
}