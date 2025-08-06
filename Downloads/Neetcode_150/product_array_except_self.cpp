/*Since its told that no division has to be done, why not just take two arrays left and right,
where each of them would contain product at left and right, at last multiply these two to get answer.*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0] = 1; //Since there is no left element
        for(int i=1;i<n;i++)
            left[i] = left[i-1] * nums[i-1];
        right[n-1] = 1;
        for(int i = n-2;i>=0;i--)
            right[i] = right[i+1]*nums[i+1];
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
            res[i] = left[i] * right[i];
        return res;
    }
};
