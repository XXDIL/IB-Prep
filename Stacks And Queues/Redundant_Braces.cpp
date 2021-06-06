/* 
	The question has a lot less corner cases as its 
	mentioned that the string A is a valid operation
*/
int Solution::braces(string A)
{
    stack<char> S;

	for(auto i : A)
	{
		if(i == '-' || i == '+' || i == '*' || i == '/') 
			S.push('.'); // any operator
		else if(i == '(') 
			S.push('(');
		else if(i == ')')
		{
			if(S.top() != '.') return 1;

			S.pop();
			S.pop();
		}
	}

	return 0;
}