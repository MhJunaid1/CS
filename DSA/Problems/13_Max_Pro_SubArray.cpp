O(n^3) Solution:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int product = 1;
                for (int k = i; k <= j; k++) {
                    product *= nums[k];
                }
                maxProduct = max(maxProduct, product);
            }
        }
        
        return maxProduct;
    }
};
O(n^2) Solution:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];
                maxProduct = max(maxProduct, product);
            }
        }
        
        return maxProduct;
    }
};
O(n) Solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        int maxProduct = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            
            maxProduct = max(maxProduct, currMax);
        }
        
        return maxProduct;
    }
};
