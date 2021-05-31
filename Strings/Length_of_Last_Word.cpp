int Solution::lengthOfLastWord(const string A)
{
    // find the last words last char index
    int last = A.size()-1;
    while(last>=0 && A[last]==' ') last--;
    
    // find the last words 1st index
    int start = last;
    while(start>=0 && A[start]!=' ') start--;
    
    return last-start;
}