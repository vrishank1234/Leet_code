class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)  # Dictionary to store grouped anagrams
        
        for word in strs:
            sorted_word = ''.join(sorted(word))  # create a unique key
            anagrams[sorted_word].append(word)   # Append the original word 
        
        return list(anagrams.values())  # Return list
