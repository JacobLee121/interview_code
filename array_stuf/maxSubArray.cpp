//
//  maxSubArray.cpp
//  array_stuf
//
//  Created by 李鑫强 on 2020/5/31星期日.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "maxSubArray.hpp"
#include <vector>
#include <algorithm>//、、#include <alogrithom>
using namespace std;

class GetMaxSubArray
{
public:
    int GetMaxSubArray_dp_list(vector<int>& nums)
    {
        /*
         dp[i] 以第i个数字结尾的子数组的最大和
         */
        vector<int> dp(nums.size()+1, 0);
        int ans = INT_MIN;
        size_t i = 0;
        for ( i = 1; i<=nums.size(); i++) {
            dp[i] = max(nums[i-1], nums[i-1] + dp[i-1]);
        }
        for (i = 1; i < dp.size(); i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int GetMaxSubArray_dp_preint(vector<int>& nums)
    {
        /*
         pre 以第当前数字结尾的子数组的最大和
         */
        
        int ans = INT_MIN;
        int pre = 0;
        size_t i = 0;
        
        for (i = 0; i<=nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }

        return ans;
    }
};

/*int main()
{
    GetMaxSubArray gs;
    vector<int> input({2,-1,3,0,-4,5});
    gs.GetMaxSubArray_dp_preint(input);
}*/
