            
            Position nextPosition = CurrentPosition();
            
            if (IsVerticalRow()) {
                ++nextPosition.row;
                if (nextPosition.row == numberOfRows) {
                    nextPosition.row -= 2;
                    if (nextPosition.row < 0) nextPosition.row = 0;
                    ++nextPosition.col;
                }
            } else {
                --nextPosition.row;
                ++nextPosition.col;
            }
            
            return nextPosition;
        }
        
        void SortZigZagForOutput() {
            sort(zigZag.begin(), zigZag.end(), [](pair<char, Position>& left, pair<char, Position>& right) {
                if (left.second.row != right.second.row) return left.second.row < right.second.row;
                return left.second.col < right.second.col;
            });
        }
        
        string Output() {
            SortZigZagForOutput();
            string output = "";
            for (auto element : zigZag) {
                output.push_back(element.first);
            }
            return output;
        }
    };
    
    
    string convert(string s, int numRows) {
        ZigZag zigZag(numRows);
        
        for (char c : s) zigZag.AddChar(c);
        
        return zigZag.Output();
    }
};
