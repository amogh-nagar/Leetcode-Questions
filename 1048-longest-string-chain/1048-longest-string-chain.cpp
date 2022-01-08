class Solution {
private:
    static bool lengthCompare(string &a, string &b) {
        return a.size() < b.size();
    }
    
	// Two pointer checking successor
    bool isValidNext(string &pre, string &curr) {
        
		// Only need to check for strings that has 1 byte difference in length
        if (pre.size() + 1 != curr.size()) {
            return false;
        }
        
		// i iterate predecessor, j iterrate current string
		// Three cases while iterating:
		//     1) pre[i] and curr[j] are all the same, return true
        //     2) one of pre[i] and curr[j] is not equal, return true
        //     3) more than one of pre[i] and curr[j] is not equal, return false
        int i = 0, j = 0;
        while (i < pre.size() && j < curr.size()) {
            if (j - i > 1) {
                return false;
            }
            if (pre[i] != curr[j]) {
                j++;
                continue;
            }
            i++;
            j++;
        }
        
        return (i == pre.size());
    }
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp (words.size(), 1);
        
		// sort input strings by size to make sure each input for our dynamic programming part is optimal
        sort(words.begin(), words.end(), lengthCompare);
        
        int res = 1;
        
		// For each word, check if previous words are valid successor, if yes, find the longest chain
        // NOTE: we only need to check strings that is 1 character less in length, this is checked in isValidNext
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isValidNext(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        
        return res;
    }
};