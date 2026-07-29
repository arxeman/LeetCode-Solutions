class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> curr=arr[0];
        ans.push_back(curr);
        for(int i=0;i<arr.size();i++){
            vector<int> temp=arr[i];
            if(curr[1]>=temp[0]){
                curr[1]=max(curr[1],temp[1]);
                ans.pop_back();
                ans.push_back(curr);
            }
            else{
                ans.push_back(temp);
                curr=temp;
            }
        }
        return ans;
    }
};