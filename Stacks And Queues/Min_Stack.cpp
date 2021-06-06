/*
    main idea is to make use of 2 stacks
    
    the min stack will store the current min element as 
    well as the history of min elements
*/

stack<int> S;
stack<int> M;

MinStack::MinStack()
{
    S = stack<int>();
    M = stack<int>();
}

void MinStack::push(int val)
{
    S.push(val);
    if(M.empty() || M.top() >= val)
        M.push(val);
}

void MinStack::pop()
{
    if(S.empty()) return;
    
    if(S.top() == M.top())
        M.pop();
    S.pop();
}

int MinStack::top()
{
    if(S.empty()) return -1;
    return S.top();
}

int MinStack::getMin()
{
    if(M.empty()) return -1;
    return M.top();
}