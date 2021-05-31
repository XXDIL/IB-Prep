class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def compareVersion(self, v1, v2):

        # putting all the revisions into an array as int
	    v1_arr = [int(rev) for rev in v1.split('.')]
        v2_arr = [int(rev) for rev in v2.split('.')]
        
        l1 = len(v1_arr)
        l2 = len(v2_arr)
        
        # padding of 0
        if l1 > l2:
            v2_arr += [0]*(l1-l2)
        elif l1 < l2:
            v1_arr += [0]*(l2-l1)
        
        # simple compare
        ans = 0;
        for i in range(max(l1, l2)):
            if v1_arr[i] > v2_arr[i]:
                return 1
            elif v1_arr[i] < v2_arr[i]:
                return -1
            
        return 0