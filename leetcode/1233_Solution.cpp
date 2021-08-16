class Solution {
    const int MAX = 4000005;
    struct tnode{
        bool eow;
        int child[27];
        void init(){
            eow = false;
            for(int i=0;i<27;i++){
                child[i] = -1;
            }
        }
    };
    tnode tpool[400005];
    int tdx;
    tnode *root;
    void init(){
        tdx = 0;
        root = &tpool[newtnode()];
    }
    int newtnode(){
        tpool[tdx].init();
        return tdx++;
    }
    int insert(string& s){
        tnode *crawl = root;
        char ch;
        int i = 0, idx = 0;
        while(i<s.length()){
            ch = s[i];
            idx = (ch == '/') ? 26 : ch -'a';
            if(crawl->child[idx] == -1) {
                crawl->child[idx] = newtnode();
            }
            if(crawl->eow && ch == '/') {
                return 0;
            }
            crawl = &tpool[crawl->child[idx]];
            i++;
        }
        crawl->eow = true;
        return 1;
    }
    void util(tnode *crawl, vector<string>& s, string& cs){
        assert(crawl);
        if(crawl->eow) {
            s.push_back(cs);
        }
        char ch;
        for(int i=0;i<26;i++){
            if(crawl->child[i] != -1){
                ch = (i + 'a');
                cs.push_back(ch);
                find(&tpool[crawl->child[i]], s, cs);
                cs.pop_back();
            }
        }
    }
    void find(tnode *crawl, vector<string>& s, string& cs){
        assert(crawl);
        if(crawl->eow) {
            util(crawl, s, cs);
            return;
        }
        char ch;
        for(int i=0;i<27;i++){
            if(crawl->child[i] != -1){
                ch = (i == 26) ? '/' : (i + 'a');
                cs += ch;
                find(&tpool[crawl->child[i]], s, cs);
                cs.pop_back();
            }
        }
    }
    void solve(vector<string>& s){
        string cs;
        find(root, s, cs);
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        init();
        for(auto s : folder) insert(s);
        vector<string> s;
        solve(s);
        return s;
    }
};