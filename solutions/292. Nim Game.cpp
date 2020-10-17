//
// WIN: 1,2,3, 5,6,7, 9,10,11, ...
// LOSE: 4,8,12, ...
//
//
​
class Solution {
public:
    const int NUMBER_OF_STONES = 3;
        
    bool canWinNim(int n) {
        return (n - 1) % (NUMBER_OF_STONES + 1) == 0
            || (n - 2) % (NUMBER_OF_STONES + 1) == 0
            || (n - 3) % (NUMBER_OF_STONES + 1) == 0;
    }
};
