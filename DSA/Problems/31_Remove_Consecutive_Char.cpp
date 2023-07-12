//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
      string removeConsecutiveCharacter(string S) {
        char* result = new char[S.length()];
        int j = 0;
        for (int i = 0; i < S.length(); i++) {
            if (i == 0) {
                result[j++] = S[i];
            } else {
                if (S[i] != result[j - 1]) {
                    result[j++] = S[i];
                }
            }
        }
        return string(result, j);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends