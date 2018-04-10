class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {

        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();

        if(len1 + len2 != len3)
            return false;

        if(len1 == 0 && len2 == 0)
            return len3 == 0;

        if(len1 == 0)
            return s2 == s3;
        if(len2 == 0)
            return s1 == s3;

        
        
        int** matrix = new int*[len2 + 1];
        for(int i = 0; i < len2 + 1; i++)
            matrix[i] = new int[len1 + 1];
        
        for(int i = 0; i < len2 + 1; i++)
        {
            for(int j = 0; j < len1 + 1; j++)
                matrix[i][j] == 0;
        }
        
        for(int i = 0; i < len2 + 1; i++)
        {
            for(int j = 0; j < len1 + 1; j++)
            {
                if(i == 0 && j == 0)
                {
                    matrix[i][j] = 1;
                    continue;
                }
                

                if((j - 1 >= 0 && matrix[i][j - 1] == 1 && s1[j - 1] == s3[i + j - 1])||
                  (i - 1 >= 0 && matrix[i - 1][j] == 1 && s2[i - 1] == s3[i + j - 1]))
                    matrix[i][j] = 1;
                
                else
                    matrix[i][j] = 0;
          
            }
        }
        
        int res = matrix[len2][len1];
        
        
        for(int i = 0; i < len2 + 1; i++)
            delete[] matrix[i];
        
        delete[] matrix;
        
        return res == 1;
    }
};
