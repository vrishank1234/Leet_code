class Solution {
public:

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;

    int s_to_t[256] = {0}; // Mapping from characters in s to characters in t
    int t_to_s[256] = {0}; // Mapping from characters in t to characters in s

    for (int i = 0; i < s.size(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check if the characters are already mapped differently
        if (s_to_t[char_s] != 0 && s_to_t[char_s] != char_t)
            return false;
        if (t_to_s[char_t] != 0 && t_to_s[char_t] != char_s)
            return false;

        // If the characters are not mapped yet, create the mapping
        if (s_to_t[char_s] == 0)
            s_to_t[char_s] = char_t;
        if (t_to_s[char_t] == 0)
            t_to_s[char_t] = char_s;
    }

    return true;
}
};