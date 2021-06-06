/*
    The question becomes extermelt easy as the
    elements are give in an array format.

    Just basic push pop.
*/

int Solution::evalRPN(vector<string>& A)
{
    stack<int> S;
    for(auto i : A)
    {
        if(i == "-" || i == "+" || i == "*" || i == "/")
        {
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            
            if(i == "-") S.push(a-b);
            else if(i == "+") S.push(a+b);
            else if(i == "*") S.push(a*b);
            else S.push(a/b);
        }
        
        else
            S.push(stoi(i));
    }
    
    return S.top();
}