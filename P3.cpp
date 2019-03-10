class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int maxlen=0;
        int lastre=-1;
        for (int i=0;i<s.size();i++){
            if (m.find(s[i])!=m.end() && lastre<m[s[i]]){
                lastre=m[s[i]];
            }
            if (i-lastre>maxlen) maxlen=i-lastre;
            m[s[i]]=i;
        }
        return maxlen;
    }
};