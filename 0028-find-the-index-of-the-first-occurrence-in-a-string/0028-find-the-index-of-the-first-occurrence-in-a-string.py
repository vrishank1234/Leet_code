class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i

        return -1

# Example usage:
sol = Solution()
haystack = "sadbutsad"
needle = "sad"
result = sol.strStr(haystack, needle)
print(f"The index of the first occurrence of '{needle}' in '{haystack}' is: {result}")
