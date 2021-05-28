'''
    palin = X|rev(X)      for even
            X|rev(X[:-1]) for odd
    
    len(X) #Palins      group
       l       2**l  (2l-1, 2l)
    ----  ---------  ----------
       1          2  (1, 2)
       2          4  (3, 4)
       3          8  (5, 6)
       4         16  (7, 8)
       5         32  (9, 10)
       6         64  (11, 12)
       7        128  (13, 14)
       8        256  (15, 16)
       9        512  (17, 18)
      10       1024  (19, 20)
      11       2048  (21, 22)
      12       4096  (23, 24)
      13       8192  (25, 26)
      14      16384  (27, 28)
      15      32768  (29, 30)
      16      65536  (31, 32)

    for Ath palindromic number, from the table
    its clear that : len(X) = log2(A+1)

    try to make a table of
      A    bin
      1    1
      2    11
      3    101

    and see the trend, by making groups

'''

class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        l = int(math.log2(A+1))

        start_X = 2**(l-1)
        start_group = 2**l - 1
        
        if (start_group) <= A <= (start_group+start_X-1): # odd len palin
            X = A-start_group+start_X
            return int(bin(X)[2:] + bin(X)[2:-1][::-1], 2)
        
        else: # even len palin
            X = A-start_group
            return int(bin(X)[2:] + bin(X)[2:][::-1], 2)