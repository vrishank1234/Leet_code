#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> brackets = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char c : s) {
            if (brackets.find(c) != brackets.end()) {
                stack.push(c);
            } else if (!stack.empty() && brackets[stack.top()] == c) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};
