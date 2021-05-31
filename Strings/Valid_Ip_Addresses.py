''' Using Regex to match IP '''
import re
def ValidIP(IP):
    digit = r'([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])'
    IPv4 = r'^(' + digit + r'\.){3}' + digit + r'$'
    
    if re.match(IPv4, IP):
        return True
    return False
 
''' Actually a really nice way to get all the lengths '''   
class Solution:
    # @param A : string
    # @return a list of strings
    def restoreIpAddresses(self, s):

        n = len(s)
        ans = []
        
        for a in range(1,4):
            for b in range(1,4):
                for c in range(1,4):
                    for d in range(1,4):
                        if a+b+c+d == n: # consider only those divisions that are of the same length
                            s1 = s[:a]
                            s2 = s[a:a + b]
                            s3 = s[a+b:a+b+c]
                            s4 = s[a+b+c:]
                            
                            IP = '.'.join([s1, s2, s3, s4])
                            if ValidIP(IP):
                                ans.append(IP)
        
        return ans;