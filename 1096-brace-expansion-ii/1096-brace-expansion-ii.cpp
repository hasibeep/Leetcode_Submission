class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parseExpr(expression, i);
        return vector<string>(res.begin(), res.end());
    }
    
    set<string> parseExpr(const string& s, int& i) {
        set<string> res;
        while (i < s.length()) {
            set<string> term = parseTerm(s, i);
            res.insert(term.begin(), term.end());
            if (i < s.length() && s[i] == ',') {
                i++;
            } else {
                break;
            }
        }
        return res;
    }
    
    set<string> parseTerm(const string& s, int& i) {
        set<string> res = {""};
        while (i < s.length() && s[i] != ',' && s[i] != '}') {
            set<string> factor = parseFactor(s, i);
            set<string> next_res;
            for (const string& a : res) {
                for (const string& b : factor) {
                    next_res.insert(a + b);
                }
            }
            res = next_res;
        }
        return res;
    }
    
    set<string> parseFactor(const string& s, int& i) {
        if (s[i] == '{') {
            i++;
            set<string> res = parseExpr(s, i);
            i++;
            return res;
        } else {
            string str = "";
            while (i < s.length() && isalpha(s[i])) {
                str += s[i];
                i++;
            }
            return {str};
        }
    }
};