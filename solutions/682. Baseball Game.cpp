class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        
        for (string op : ops) {
            if (op == "+") {
                scores.push_back(scores.back() + *(scores.end() - 2));
            } else if (op == "D") {
                scores.push_back(2 * scores.back());
            } else if (op == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(op));
            }
        }
        
        int total = 0;
        for (int score : scores) total += score;
        return total;
    }
};
