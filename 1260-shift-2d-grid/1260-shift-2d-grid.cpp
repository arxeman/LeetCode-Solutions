class Solution {
public:
    int m,n;
    void rotate(vector<vector<int>> &arr){
        int last=arr[m-1][n-1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int prev=arr[i][j];
                arr[i][j]=last;
                last=prev;
            }
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        k=k%(m*n);
        for(int i=0;i<k;i++){
            rotate(grid);
        }
        return grid;
    }
};