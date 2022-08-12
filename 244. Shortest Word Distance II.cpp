/*Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.
 

Example 1:

Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1
 

Constraints:

1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
At most 5000 calls will be made to shortest.
*/
class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    WordDistance(vector<string>& wordsDict) {
       for(int i=0;i<wordsDict.size();i++) 
       {
           mp[wordsDict[i]].push_back(i);
       }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for(int i=0,j=0;i<mp[word1].size() && j<mp[word2].size();
            mp[word1][i]<mp[word2][j]? i++ : j++)
            
        {
            res = min(res,abs(mp[word1][i]-mp[word2][j]));
            
        }
        return res;
    }
};