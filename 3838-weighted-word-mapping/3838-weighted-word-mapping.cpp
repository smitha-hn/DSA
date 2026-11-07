
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans = "";

        for (string word : words) {
            int sum = 0;

            // Calculate total weight of the word
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            // Find remainder
            int rem = sum % 26;

            // Reverse alphabetical mapping
            char result = 'z' - rem;

            ans += result;
        }

        return ans;
    }
};
