class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        a_idx = len(a) - 1
        b_idx = len(b) - 1
        carry = 0
        ret = ""

        while(a_idx >= 0 and b_idx >= 0):
            res = ""
            c = 0
            if a[a_idx] == '1' and b[b_idx] == '1':
                res = '0'
                c = 1
            elif int(a[a_idx]) or int(b[b_idx]):
                    res = '1'
            else:
                res = '0'
            res = int(res)
            
            if carry and res:
                ret += '0'
            elif carry:
                carry = c
                ret += '1'
            elif res:
                ret += '1'
            else:
                ret += '0'
                carry = c
                
                
            a_idx -= 1
            b_idx -= 1
                
        while a_idx >= 0:
            if int(a[a_idx]) and carry:
                ret += '0'
            elif carry:
                carry = 0
                ret += '1'
            else:
                ret += a[a_idx]
            a_idx -= 1
            
        while b_idx >= 0:
            if int(b[b_idx]) and carry:
                ret += '0'
            elif carry:
                carry = 0
                ret += '1'
            else:
                ret += b[b_idx]
            
            b_idx -= 1
        
        if carry:
            ret += '1'
        
        return ret[::-1]
        