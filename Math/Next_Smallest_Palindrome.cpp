// adds 1 to a string
string add_1(string x)
{
    int carry = 1;
    int i = x.size()-1;
    while(i>=0 && carry)
    {
        int sum = (x[i] - '0') + carry;

        x[i--] = '0' + sum%10;
        carry = sum/10;
    }

    if(carry)
        x = '1' + x;

    return x;
}

// makes a palindrome using x or x_1 accordingly
string makePalin(string x, int n)
{
    string back = x;

    if(n&1)
        back.pop_back();

    reverse(back.begin(), back.end());

    return x + back;
}

/*
    Observation : 
        next smallest palin will be either 
        from lower limit or from the higher limit

    A = "23545"
        lower limit = 23532
        higher limit = 23632
*/
string Solution::solve(string A)
{
    if(A == "9")
        return "11";

    int n = A.size();
    string x = A.substr(0, n/2 + (n&1));

    string lower_limit = makePalin(x, n);
    if(lower_limit > A)
        return lower_limit;

    string x_1 = add_1(x);

    if(x_1.size() > x.size())
    {
        string b;

        if(n&1)
            b = x_1.substr(0, x_1.size()-2);
        else
            b = x_1.substr(0, x_1.size()-1);

        reverse(b.begin(), b.end());

        return x_1 + b;
    }

    return makePalin(x_1, n);
}