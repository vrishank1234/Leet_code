class Solution {
public:

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> s_to_t_map;
    unordered_map<char, char> t_to_s_map;

    for (int i = 0; i < s.size(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check if the character from s is already mapped to a different character in t
        if (s_to_t_map.find(char_s) != s_to_t_map.end() && s_to_t_map[char_s] != char_t)
            return false;

        // Check if the character from t is already mapped to a different character in s
        if (t_to_s_map.find(char_t) != t_to_s_map.end() && t_to_s_map[char_t] != char_s)
            return false;

        // If the characters are not mapped yet, create the mapping
        if (s_to_t_map.find(char_s) == s_to_t_map.end())
            s_to_t_map[char_s] = char_t;
        if (t_to_s_map.find(char_t) == t_to_s_map.end())
            t_to_s_map[char_t] = char_s;
    }

    return true;
}

};