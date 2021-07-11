/*
    The only issue with this question is that 
    1->A and 26->Z
    
    so this is not exactly a base 26 conversion.
*/
string Solution::convertToTitle(int n)
{
    string ans = "";
    while(n != 0)
    {
        int rem = n%26;
        
        if(rem == 0)
        {
            ans = 'Z' + ans;
            n = n/26 - 1;
        }
        
        else
        {
            ans = char('A' + rem - 1) + ans;
            n /= 26;
        }
    }
    
    return ans;
}