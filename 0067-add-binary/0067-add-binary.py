class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = []
        carry = 0

        i, j = len(a) - 1, len(b) - 1

        while i >= 0 or j >= 0 or carry:
            digit_a = int(a[i]) if i >= 0 else 0
            digit_b = int(b[j]) if j >= 0 else 0
            carry, current_sum = divmod(digit_a + digit_b + carry, 2)
            result.append(str(current_sum))
            i, j = i - 1, j - 1

        return ''.join(result[::-1])

solution = Solution()

a1, b1 = "11", "1"
result1 = solution.addBinary(a1, b1)
print(f"Input: a = {a1}, b = {b1}\nOutput: {result1}")

a2, b2 = "1010", "1011"
result2 = solution.addBinary(a2, b2)
print(f"\nInput: a = {a2}, b = {b2}\nOutput: {result2}")
