#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyClass {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    return true;
                }
            }
           
        }
        return false;
    }
    bool usingHashSet(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            if (numSet.count(num) > 0) {
                return true;
            }
            numSet.insert(num);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2, 4, 7, 3, 5};

    MyClass myObj;
    bool result = myObj.containsDuplicate(nums);

    cout << "Is array contains duplicate? " << result << endl;

    return 0;
}
