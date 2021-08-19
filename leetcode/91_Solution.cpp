class Solution {
    char Z = '0';
public:
    int numDecodings(string s) {
        vector<int> T(s.length() + 1, 0);
        T[0] = 1, T[1] = s[0] != '0' ? 1 : 0;
        
        for(int i=2;i<=s.length();i++){
            T[i] = s[i-1] != '0' ? T[i-1] : 0;
            if(s[i-2] != '0' && (s[i-2]-Z)*10 + (s[i-1] - Z) <= 26) {
                T[i] += T[i-2];
            }
        }
        return T[s.length()];
    }
};