class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<10)
            return ans;
        auto value=[](char c){
            if(c=='A') return 1;
            if(c=='C') return 2;
            if(c=='G') return 3;
            return 4;
        };
        const long long base=5;
        long long power=1;
        for(int i=0;i<9;i++){
            power*=base;
        }
        unordered_set<long long> seen;
        unordered_set<long long> repeated;
        long long hash=0;
        for(int i=0;i<10;i++){
            hash=hash*base+value(s[i]);
        }
        seen.insert(hash);
        for(int i=10;i<s.size();i++){
            hash-=value(s[i-10])*power;
            hash=hash*base+value(s[i]);
            if(seen.count(hash)&&!repeated.count(hash)){
                ans.push_back(s.substr(i-9,10));
                repeated.insert(hash);
            }
            seen.insert(hash);
        }
        return ans;
    }
};