class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        start = 0
        end = int(sqrt(c))

        while(start <= end):
            value = (start*start) + (end*end)
            if(value == c):
                return True
            elif(value > c):
                end = end-1
            else:
                start = start+1
        
        return False
        