*****************************************************************************************  Question  **************************************************************************************************



Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
Only possible 2 unique permutations are
4 5
5 4
Your Task:
You don't need to read input or print anything. You only need to complete the function uniquePerms() that takes an integer n, and an array arr of size n as input and returns a sorted list of lists containing all unique permutations of the array.

Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)





*****************************************************************************************  Solution  **************************************************************************************************

  //{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void  solve(vector<int>arr,unordered_map<int,int>&mp,set<int>se,int i,vector<vector<int>>&ans,vector<int>v){
    if(i>=arr.size()){
        //cout<<"hello";
        ans.push_back(v);
        return;
    }
     for (int element : se) {
       // cout<<"hi";
       if(mp[element]>0){
           mp[element]--;
           v.push_back(element);
        solve(arr,mp,se,i+1,ans,v);
         mp[element]++;
         v.pop_back();
       }
       

  }
}
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
    unordered_map<int,int>mp;
    set<int>se;
    for(auto val:arr){
        se.insert(val);
        mp[val]+=1;
    }
   vector<vector<int>>ans;
   vector<int>v;

    solve(arr,mp,se,0,ans,v);
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
