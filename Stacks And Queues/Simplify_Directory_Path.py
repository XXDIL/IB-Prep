'''
    chose python bcus of split()

    rest is trivial
'''
class Solution:
	# @param path : string
	# @return a strings
	def simplifyPath(self, path):
        stack = ['/']
        for i in path.split('/'):
            if i=='' or i=='.' or (stack[-1]=='/' and i=='..'):
                pass
            
            elif i=='..':
                stack.pop()
            
            else:
                stack.append(i+'/')
                
        if len(stack) == 1:
            return '/'
        
        return ''.join(stack)[:-1]