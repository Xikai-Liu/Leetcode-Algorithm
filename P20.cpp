class Solution {
public:
    bool isValid(string s) {
        stack<char> zf;
        for (int i=0;i<s.size();i++){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') zf.push(s[i]);
            if (s[i]==')'){
                if (zf.empty()) return false;
                if (zf.top()!='(') return false;
                zf.pop();
            }
            if (s[i]==']'){
                if (zf.empty()) return false;
                if (zf.top()!='[') return false;
                zf.pop();
            }
            if (s[i]=='}'){
                if (zf.empty()) return false;
                if (zf.top()!='{') return false;
                zf.pop();
            }
        }
        if (zf.empty()) return true;
        return false;
    }
};
