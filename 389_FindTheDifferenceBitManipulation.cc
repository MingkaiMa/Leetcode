class Solution {
public:
    char findTheDifference(string s, string t) {

        char c = 0;
        for(auto& cha: s)
            c = c ^ cha;
        for(auto& cha: t)
            c = c ^ cha;
        return c;

    }
};
