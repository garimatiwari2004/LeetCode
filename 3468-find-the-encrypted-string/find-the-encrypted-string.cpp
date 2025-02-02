class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        k = k % n;

        string result;
        for (int i = 0; i < n; ++i) {
            int idx = (i + k) % n;
            result += s[idx];
        }
        return result;
    }
};