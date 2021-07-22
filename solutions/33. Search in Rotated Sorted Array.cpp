class Solution {
public:
    int findRotation(const vector<int>& nums, int left, int right) {
        if (left == right) return left;
        if (right - left == 1) return nums[left] < nums[right] ? left : right;
        
        int middle = left + (right - left) / 2;
        
        int middleVal = nums[middle];
        int leftVal = nums[left];
        int rightVal = nums[right];
        
        if (middleVal > leftVal) {
            // Solution is in the right half.
            return findRotation(nums, middle, right);
        }
        
        if (middleVal < rightVal) {
            // Solution is in the left half.
            return findRotation(nums, left, middle);
        }
        cout << 'ERROR' << endl;
        return 0; 
    }
    
    class RotatedArray {
        public: 
        vector<int> vec_;
        int rotation_;
        
        RotatedArray(const vector<int>& vec, int rotation) {
            vec_ = vec;
            rotation_ = rotation;
        }   
        
        int at(int index) {
            return vec_[(index + rotation_) % vec_.size()];
        }
        
        int size() {
            return vec_.size();
        }
    };
    
    int binarySearch(RotatedArray nums, int target, int start, int end) {
        int middle = start + (end - start) / 2;
        
        if (nums.at(middle) == target) return middle;
        
        if (start >= end) return -1;
        
        if (nums.at(middle) < target) return binarySearch(nums, target, middle + 1, end);
        return binarySearch(nums, target, start, middle - 1);
        
    }
    
    int search(vector<int>& nums, int target) {
        int rotation = nums[0] < nums[nums.size() - 1] ? 0 : findRotation(nums, 0, nums.size() - 1);
        
        RotatedArray arr = RotatedArray(nums, rotation);
        
        int res = binarySearch(arr, target, 0, nums.size() - 1);
        return res == -1 ? -1 : (res + rotation) % nums.size();
    }
};
