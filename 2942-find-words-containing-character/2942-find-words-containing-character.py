class Solution:
    def findWordsContaining(self, words, x):
        return [i for i, word in enumerate(words) if x in word]

# Example usage:
solution = Solution()

# Example:
words_example = ["leet", "code"]
character_to_find_example = "e"

result_example = solution.findWordsContaining(words_example, character_to_find_example)
print(f"Example: {result_example}")
