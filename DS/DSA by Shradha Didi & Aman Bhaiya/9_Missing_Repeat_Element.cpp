//link https://www.interviewbit.com/problems/repeat-and-missing-number-array/
//My solution with extra memroy being used
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int *withM=new int[A.size()],firstNumber,secondNumber;//with Memory
    vector<int> results; 
    for(int i=0;i<A.size();i++){
        withM[i]=0;
    }
    for(int i=0;i<A.size();i++){
        withM[A[i]-1]+=1;
    }
    for(int i=0;i<A.size();i++){
        if(withM[i]>1){
            firstNumber=i+1;
        }
        if(withM[i]==0){
            secondNumber=i+1;
        }
    }
    results.push_back(firstNumber);
    results.push_back(secondNumber);
    return results;
}
//Optimal by chatgpt:
#include <vector>

vector<int> repeatedNumber(const vector<int> &A) {
    long long xorSum = 0;
    long long xorArr = 0;
    int n = A.size();

    // XOR all the elements with their indices
    for (int i = 0; i < n; i++) {
        xorSum ^= (i + 1);
        xorArr ^= A[i];
    }

    // XOR xorSum with xorArr to get the missing and repeated elements combined
    long long xorResult = xorSum ^ xorArr;

    // Find the rightmost set bit in xorResult
    long long rightmostSetBit = xorResult & ~(xorResult - 1);

    long long missingOrRepeated = 0;
    long long missingOrRepeatedArr = 0;

    // XOR the elements with the rightmost set bit
    for (int i = 0; i < n; i++) {
        if (A[i] & rightmostSetBit)
            missingOrRepeated ^= A[i];
        else
            missingOrRepeatedArr ^= A[i];
    }

    // XOR the indices with the rightmost set bit
    for (int i = 1; i <= n; i++) {
        if (i & rightmostSetBit)
            missingOrRepeated ^= i;
        else
            missingOrRepeatedArr ^= i;
    }

    // Check which one is missing and which one is repeated
    for (int i = 0; i < n; i++) {
        if (A[i] == missingOrRepeated) {
            return {missingOrRepeated, missingOrRepeatedArr};
        }
    }

    // If no repeated or missing element found, return an empty vector
    return {};
}
//Solution in the submission section: not sure correct or not

pls tell me why it not work for the long testcases 


vector<int> Solution::repeatedNumber(const vector<int> &arr) {

    int n = arr.size();

            long long int sn = (n*(n+1))/2;

        long long int sn2 = (n*(n+1)*(2*n+1))/6;

        long long int s = 0, s2 = 0;

        

        for (int i=0; i<n; i++) {

            s  += arr[i];

            s2 += (long long)arr[i] * (long long)arr[i];

        }

        

        long long int val1 = sn-s;

        long long int val2 = sn2-s2;

        val2 = val2/val1;

        long long int x = (val1 + val2)/2;

        long long int y = x - val1;

        return {y, x};

}