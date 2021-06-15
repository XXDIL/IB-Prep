/*
    u have a choice, 
    if u want to place '(' then there has to be at least 1 '(' in the options.
    if u want to place ')' then there has to be atleast lesser number of '(' than ')' or '(' == 0

    draw the recursive tree, itll become trivial.
*/
void help(int open, int close, string temp, vector<string>& ans)
{
    if(open == 0 && close == 0)
    {
        ans.push_back(temp);
        return;
    }
    
    if(open == close) 
        return help(open-1, close, temp+'(', ans);
    
    if(open != 0)
        help(open-1, close, temp+'(', ans);
    if(close != 0)
        help(open, close-1, temp+')', ans);
}

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> ans;
    string temp;
    
    help(n, n, temp, ans);
    
    return ans;
}