class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size()==0 && needle.size()==0) return 0;
        string p=haystack;
        int now=0;
        while (now<p.size()){
            int now1=now,now2=0;
            while (now1<p.size() && now2<needle.size() && p[now1]==needle[now2]){
                now1++;now2++;
            }
            if (now2==needle.size()) return now1-needle.size();
            now++;
        }
        return -1;
    }
};