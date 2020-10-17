class Solution {
public:
    unordered_map<int, int> store = { {0, 0}, {1, 1} };
    
    int fib(int N) {
        if (store.find(N) != store.end()) return store[N];
        int fib_value = fib(N - 1) + fib(N - 2);
        store[N] = fib_value;
        return fib_value;
    }
};
