class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
        }

        vector<int> tCount(26, 0);
        for (int i = 0; i < t.length(); i++) {
            tCount[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (sCount[i] != tCount[i]) {
                return (false);
            }
        }

        return (true);
    }
};