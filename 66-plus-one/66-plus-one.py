class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        idx = len(digits) - 1

        while idx >= 0 and carry:
            if digits[idx] + 1 >= 10:
                digits[idx] = 0
            else:
                digits[idx] += carry
                carry = 0
            idx -= 1
        
        if carry:
            digits.insert(0, 1)
        
        return digits