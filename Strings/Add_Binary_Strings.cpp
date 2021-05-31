string Solution::addBinary(string a, string b)
{
    int la = a.size();
    int lb = b.size();
    
    // make 'a' the bigger string
    if(la < lb)
    {
        swap(a, b);
        swap(la, lb);
    }
    
    // paddding b with la-lb, 0's
    while(la-lb)
    {
        b = '0' + b;
        lb++;
    }
    
    int C = 0;
    for(int i=la-1;i>=0;--i)
    {
        int ia = a[i]-'0';
        int ib = b[i]-'0';
                    
        a[i] = char('0'+(ia^ib^C));
        C = C ? ia|ib : ia&ib;
    }
    
    // Final Carry
    if(C) a = '1' + a;
    
    return a;
}