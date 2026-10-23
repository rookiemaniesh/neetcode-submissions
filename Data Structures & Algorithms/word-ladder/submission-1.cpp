class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return 0;
        if (!words.count(beginWord))
            wordList.push_back(beginWord);
        unordered_map<string,vector<string>> adj;
        for (int x = 0; x < wordList.size(); x++) {
            for (int y = x + 1; y < wordList.size(); y++) {
                int cnt = 0;
                for (int i = 0; i < beginWord.length(); i++) {
                    if (wordList[x][i] != wordList[y][i])
                        cnt++;
                }
                if (cnt == 1) {
                    adj[wordList[x]].push_back(wordList[y]);
                    adj[wordList[y]].push_back(wordList[x]);
                }
            }
        }
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string w = q.front();
                q.pop();
                if (w == endWord)
                    return ans;
                for (auto it : adj[w]) {
                    if(vis.count(it))continue;
                    vis.insert(it);
                    q.push(it);
                }
            }
                ans++;
        }
        return 0;
    }
};