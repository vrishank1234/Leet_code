class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Initialize pointers for the start and end of the string
        start, end = 0, len(s) - 1

        while start < end:
            # Move the pointers towards each other until a valid alphanumeric character is found
            while start < end and not s[start].isalnum():
                start += 1
            while start < end and not s[end].isalnum():
                end -= 1

            # Compare the characters (case-insensitive)
            if s[start].lower() != s[end].lower():
                return False

            # Move pointers towards each other
            start += 1
            end -= 1

        return True

# Example usage:
solution = Solution()

input_str1 = "A man, a plan, a canal: Panama"
output1 = solution.isPalindrome(input_str1)
print(f"Input: {input_str1}\nOutput: {output1}")

input_str2 = "race a car"
output2 = solution.isPalindrome(input_str2)
print(f"\nInput: {input_str2}\nOutput: {output2}")

input_str3 = " "
output3 = solution.isPalindrome(input_str3)
print(f"\nInput: {input_str3}\nOutput: {output3}")
