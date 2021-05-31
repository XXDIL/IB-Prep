/* 
    Given characters only till 'M' our max possible value is 3999 = MMMCMXCIX 
    So we can make a lookup of values for each decimal position "1000 100 10 1" \
*/
string Solution::intToRoman(int num)
{
    vector<string> ones =  {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> thousands = {"", "M", "MM", "MMM"};
    
    string ans = "";
    
    ans = ones[num%10] + ans;
    num /= 10;
    
    ans = tens[num%10] + ans;
    num /= 10;
    
    ans = hundreds[num%10] + ans;
    num /= 10;
    
    ans = thousands[num%10] + ans;
    num /= 10;
    
    return ans;
}