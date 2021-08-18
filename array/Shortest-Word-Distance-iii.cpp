class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1Index=-1;
        int word2Index=-1;
        int ret = wordsDict.size();
        for(int i=0; i< wordsDict.size(); i++)
        {
            if(wordsDict[i]==word1)
            {
               word1Index = i; 
               if(word2Index!=-1)
                   ret = min(ret, abs(word1Index - word2Index));
               if(word1 == word2 ) // close two index is smallest. we use word2Index record prev. word1index recor current
               {
                   word2Index = word1Index;
               }
            }
            else if(wordsDict[i]==word2)
            {
                word2Index =i;
               if(word1Index!=-1)
                   ret = min(ret, abs(word2Index - word1Index));                
            }
        } 
        return ret; 
    }
};
