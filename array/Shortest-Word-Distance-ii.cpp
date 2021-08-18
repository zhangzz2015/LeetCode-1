class WordDistance {
public:
    unordered_map<string, vector<int>> recordWords;
    int wordsDictSize =0; 
    WordDistance(vector<string>& wordsDict) {
        
        for(int i=0; i< wordsDict.size(); i++)
        {
            recordWords[wordsDict[i]].push_back(i);
        }
        wordsDictSize = wordsDict.size();
    }
    
    int shortest(string word1, string word2) {
        int ret = wordsDictSize; 
        for(int i=0; i< recordWords[word1].size(); i++)
        {
            for(int j=0; j< recordWords[word2].size(); j++)
            {
                ret = min(ret, abs(recordWords[word1][i] - recordWords[word2][j]));
            }
        }
        return ret; 
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
