class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        // use two pointer. 
        int word1Pos=-1; 
        int word2Pos=-1;
        int ret = wordsDict.size();        
        for(int i=0; i< wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1)
            {
                word1Pos = i;
                if(word2Pos!=-1)
                {
                   ret = min(ret, abs(word1Pos- word2Pos)); 
                }
            }
            else if(wordsDict[i] == word2)
            {
                word2Pos = i;
                if(word1Pos!=-1)
                {
                   ret = min(ret, abs(word2Pos- word1Pos)); 
                }                
            }
        }
        return ret; 
        
    }
};
