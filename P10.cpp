class Solution {
public:
    bool isMatch(string s, string p) {
        const char *ss=s.c_str();
        const char *pp=p.c_str();
        for (char c=*pp; c != '\0'; ++ss, c=*pp) {
            if (pp[1] != '*') ++pp;
            else if (isMatch(ss, pp+2)) return true;
            if (!(c == *ss || (c == '.' && *ss != '\0'))) return false;
        }
        return *ss == '\0';
    }
};