class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = abs(D - B) * abs(C - A) + abs(H - F) * abs(G - E);
        
        int lefth = max(A, E);
        int righth = min(C, G);
        
        
        if(lefth >= righth)
            return res;
            
        int newWidth = abs(righth - lefth);
        
        int downh = max(B, F);
        int toph = min(D, H);

        
        if(downh >= toph)
            return res;
        
        int newHeight = abs(toph - downh);
        
        res -= newWidth * newHeight;
        
        
        
        return res;
    }
};
