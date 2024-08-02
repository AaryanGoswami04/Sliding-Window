class Solution {
public:
/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7*/
//Optimised approach:
//TC:O(N)
//SC:O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0, j=0;
        deque<int>dq;

        while(j < nums.size()){
            while(!dq.empty() && dq.back() < nums[j]) dq.pop_back();
            dq.push_back(nums[j]);

            if(j-i+1 == k){
                ans.push_back(dq.front());

                if(nums[i] == dq.front()) dq.pop_front();
                
                i++;
            }
          j++;
        }
        return ans;
    }
};
