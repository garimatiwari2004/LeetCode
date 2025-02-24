class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int lef1 = 0, lef2 = 1;
        int rig1, rig2;
        if (n & 1) {
            rig2 = n, rig1 = n - 1;
        } else {
            rig1 = n, rig2 = n - 1;
        }
        function<bool(string)> checko = [&](string ss) {
            int nn = ss.size();
            int lef = 0, rig = nn - 1;
            while (lef <= rig) {
                if (ss[lef] != ss[rig])
                    return false;
                lef++;
                rig--;
            }
            return true;
        };
        function<int(int)> check = [&](int cur) {
            for (int i = 0; i <= n - cur; i++) {
                string temp = "";
                for (int j = i; j < i + cur; j++) {
                    temp += s[j];
                }
                if (checko(temp))
                    return i;
            }
            return -1;
        };
        while (lef1 < rig1) {
            int mid = (lef1 + rig1) / 2;
            if (mid & 1)
                mid++;
            if (check(mid) != -1)
                lef1 = mid;
            else
                rig1 = mid - 2;
        }
        while (lef2 < rig2) {
            int mid = (lef2 + rig2) / 2;
            if (mid & 1)
                ;
            else
                mid++;
            if (check(mid) != -1)
                lef2 = mid;
            else
                rig2 = mid - 2;
        }
        int ans = max(lef1, lef2);
        int anso = check(ans);
        string ansi = "";
        for(int i=anso;i<anso+ans;i++) ansi+=s[i];
        return ansi;
    }
};