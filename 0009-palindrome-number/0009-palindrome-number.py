class Solution:
    def isPalindrome(self, x):
        str_x = str(x)
        
        return str_x == str_x[::-1]

# Example usage:
obj = Solution()
param_1 = 121
result = obj.isPalindrome(param_1)
print(result)
