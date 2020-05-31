//
//  maximumSum.cpp
//  array_stuf
//
//  Created by 李鑫强 on 2020/6/1星期一.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "maximumSum.hpp"
#include <vector>
#include <algorithm>
using namespace std;
class MaximumSum {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n);
        vector<int> g(n);
        f[0] = arr[0];
        g[0] = INT_MIN/2;
        for(int i=1;i<n;i++){
            // 没有删除过的转移函数
            f[i] = max(f[i-1]+arr[i],arr[i]);
            // 删除过的转移函数，f[i-1]代表删除arr[i], g[i-1]+arr[i]表示删除的是arr[i] 之前的
            g[i] = max(g[i-1]+arr[i],f[i-1]);
            
        }
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            res = max(res,max(f[i],g[i]));
        }
        return res;
    }
};
int main()
{
    MaximumSum ms;
    vector<int> input({-1,2,3,-5});
    ms.maximumSum(input);
}

