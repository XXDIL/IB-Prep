/*
    try making the recursive tree

                254
        524     458     245
        542     425
    
    tipical i j loop
*/
void help(string S, int n, int i, int B, int& Max)
{
    if(B == 0)
        return;
 
    for(i; i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            string temp = S;
            swap(temp[i], temp[j]);
 
            Max = max(Max, stoi(temp));
 
            help(temp, n, i+1, B-1, Max);
        }
    }
}
 
string Solution::solve(string A, int B)
{
    int Max = stoi(A);
    help(A, A.size(), 0, B, Max);
    
    return to_string(Max);
}