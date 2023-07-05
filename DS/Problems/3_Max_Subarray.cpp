#include <iostream>
#include <vector>

using namespace std;

class MaxSubarray {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currentSum=max(nums[i],nums[i]+currentSum);
            maxSum=max(currentSum,maxSum);
        }
        return maxSum;
    }
};

int main() {
    vector<int> nums = {2, 4, -9, 3, 5};

    MaxSubarray MaxSubarray;
    int maxSubArraySum = MaxSubarray.maxSubArray(nums);

    cout << "Maximum subarray sum: " << maxSubArraySum << endl;

    return 0;
}
