/*
    The idea is to put "right" closing bracket if we encountered the matching open bracket into the stack.
    Then check if our closing braket matches the "real" closing bracket, and the match is true - pop the element from the stack.
    In the end of the function there is general check for the right number of "pair brackets" (if our stack still contains something, then number of open brackets != number of cloding one).
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (st.empty()) {
                return false;
            }
            else if (st.top() == s[i]) {
                st.pop();
            } else if (st.top() != s[i]) {
                st.pop();
                return false;
            }
        }
        return st.empty();
    }
};