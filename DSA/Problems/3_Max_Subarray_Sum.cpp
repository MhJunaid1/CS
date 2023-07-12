// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

class MaxSubarray {
public:
   
    int bruteForceCube(vector<int>& nums){
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int tempSum=0;
                for(int k=i;k<=j;k++){
                    tempSum+=nums[k];
                }
                if(tempSum>maxSum){
                    maxSum=tempSum;
                }
            }
        }
        return maxSum;
    }
    int bruteForceSquare(vector<int>& nums){
        int n = nums.size();
        int maxSum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
    long long maxSubarraySum(int arr[], int n) //Take u forward solution with intution
    {
        long long maxi = LONG_MIN; // maximum sum
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            if (sum > maxi) {
                maxi = sum;
            }

            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }

        // To consider the sum of the empty subarray
        // uncomment the following check:

        //if (maxi < 0) maxi = 0;

        return maxi;
    }
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
    vector<int> nums = {8, 4, -9, 3, 15};

    MaxSubarray MaxSubarray;
    int maxSubArraySumCube = MaxSubarray.bruteForceCube(nums);

    //int maxSubArraySum = MaxSubarray.maxSubArray(nums);

    cout << "Maximum subarray sum: " << maxSubArraySumCube << endl;

    return 0;
}
