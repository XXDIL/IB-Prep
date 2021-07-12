// abcd * x
string singeMultiply(string A, int n, int x)
{
    int i=n-1;
    int carry = 0;
    while(i>=0)
    {
        int prod = (A[i] - '0') * x + carry;

        A[i--] = '0' + prod%10;
        carry = prod/10;
    }

    if(carry)
        A = to_string(carry) + A;

    return A;
}

// abcd + absdef -> 00abcd + absdef
string add(string A, string B)
{
    if(A.size() > B.size())
        B = string(A.size() - B.size(), '0') + B;
    else
        A = string(B.size() - A.size(), '0') + A;

    int i = A.size() - 1;
    int carry = 0;
    while(i>=0)
    {
        int sum = carry + (A[i]-'0') + (B[i]-'0');

        carry = sum / 10;
        A[i--] = '0' + sum%10;
    }

    if(carry)
        A = to_string(carry) + A;

    return A;
}

// elementary multiplication method
string Solution::multiply(string A, string B)
{
    if(A == "0" || B == "0")
        return "0";

    int m = A.size();
    int n = B.size();

    string ans = "0";
    for(int i=n-1;i>=0;--i)
    {
        string temp = singeMultiply(A, m, B[i]-'0') + string(n-1-i, '0');

        ans = add(ans, temp);
    }

    // removing leading 0's
    int i = 0;
    while(i<ans.size() && ans[i] == '0')
        i++;

    ans = ans.substr(i, ans.size()-i);

    return ans;
}