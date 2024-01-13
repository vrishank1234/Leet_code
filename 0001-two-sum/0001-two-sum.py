class Solution:
    def twoSum(self, nums, target):
        num_dict = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_dict:
                return [num_dict[complement], i]
            num_dict[num] = i
        return []

# Example usage:
solution = Solution()

# Example 1:
nums1 = [2, 7, 11, 15]
target1 = 9
result1 = solution.twoSum(nums1, target1)
print(f"Example 1: {result1}")

# Example 2:
nums2 = [3, 2, 4]
target2 = 6
result2 = solution.twoSum(nums2, target2)
print(f"Example 2: {result2}")

# Example 3:
nums3 = [3, 3]
target3 = 6
result3 = solution.twoSum(nums3, target3)
print(f"Example 3: {result3}")
