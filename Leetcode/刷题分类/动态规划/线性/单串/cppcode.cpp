#include "head.h"
//LIS-----------------------------------------
/* 
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
300
 */
//dp-----时间过长！
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            res=max(dp[i],res);
        }
        return res;
    }
};
//*****
//贪心----better
//找增速最慢的
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0,n=nums.size();
        vector<int> help(n);
        help[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>help[len]){
                help[++len]=nums[i];
            }else{
                int k=lower_bound(help.begin(),help.begin()+len,nums[i])-help.begin();
                help[k]=nums[i];
            }
        }
        return len+1;
    }
};
/* 
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。
673
*/
//dp
//dp:记录最长序列的长度，dir:记录这个长度下的序列的数量
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxn=0,res=0;
        vector<int> dp(n,1),dir(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        dir[i]=dir[j];
                    }else if(dp[i]==dp[j]+1){
                        dir[i]+=dir[j];
                    }
                }
            }
            if(dp[i]>maxn){
                maxn=dp[i];
                res=dir[i];
            }else if(dp[i]==maxn){
                res+=dir[i];
            }
        }
        return res;
    }
};
//*****
//尝试用贪心-----比较麻烦！
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),len=0,res=0;
        vector<int> help(n);
        for(int i=0;i<n;i++){
            int k=lower_bound(help.begin(),help.begin()+len+1,nums[i])-help.begin();
            help[k]=nums[i];
            if(k>len){
                res=1;
                len=k;
            }else if(k==len){
                res++;
            }
        }
        return res;
    }
};
/* 
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
354
 */
//dp---TLE
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]>j[1];};
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
//[1,7],[2,6],[5,9],[6,8],[7,8]
//[2,3],[5,4],[6,4],[6,7];
//贪心---引用就不会超时
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]>j[1];};
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size(),len=0;
        vector<int> help(n);
        help[0]=envelopes[0][1];
        for(int i=1;i<n;i++){
            int k=lower_bound(help.begin(),help.begin()+len+1,envelopes[i][1])-help.begin();
            help[k]=envelopes[i][1];
            len=max(len,k);
        }
        return len+1;
    }
};
/* 
堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。
实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。

输入使用数组[wi, di, hi]表示每个箱子。
面试题 08.13. 堆箱子
 */
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {

    }
};
/* 
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
435
 */
//普通做法--贪心找“瘦”的区间
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(intervals.begin(),intervals.end(),cmp);
        int R=-100000,ans=0;
        for(auto vec:intervals){
            int l=vec[0],r=vec[1];
            if(l>=R){
                R=r;
                continue;
            }
            if(r<R){
                R=r;
            }
            ans++;
        }
        return ans;
    }
};
//[1,7],[2,6],[5,9],[6,8],[7,8]
//[1,4],[2,3],[5,6],[5,7],[6,8]
//dp做法--最长子序列---TLE                                                 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(intervals[i][0]>=intervals[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return n-dp[n-1];
    }
};
//dp做法用贪心二分就可以！
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //如果边界可以包含则第二元素递增
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size(),len=0;
        vector<int> help(n,-50001);
        help[0]=intervals[0][1];
        for(int i=1;i<n;i++){
            //相邻
            int k=upper_bound(help.begin(),help.begin()+len+1,intervals[i][0])-help.begin();
            if(k>len||help[k]>intervals[i][1]){
                help[k]=intervals[i][1];
            }
            len=max(k,len);
        }
        return n-1-len;
    }
};
/* 
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
646
 */
//与上题唯一不同就是不允许相邻
//贪心
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(pairs.begin(),pairs.end(),cmp);
        int R=INT_MIN,res=0;
        for(auto vec:pairs){
            int l=vec[0],r=vec[1];
            if(l>R){
                res++;
                R=r;
            }else{
                R=min(r,R);
            }
        }
        return res;
    }
};
//dp--没超时
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};
//dp做法用贪心二分就可以！
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size(),len=0;
        vector<int> help(n,-50001);
        help[0]=pairs[0][1];
        for(int i=1;i<n;i++){
            //不相邻
            int k=lower_bound(help.begin(),help.begin()+len+1,pairs[i][0])-help.begin();
            if(k>len||help[k]>pairs[i][1]){
                help[k]=pairs[i][1];
            }
            len=max(k,len);
        }
        return len+1;
    }
};
/* 
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
452
 */
//贪心：只要找出有最多有多少不重叠的气球即可，类似435
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(points.begin(),points.end(),cmp);
        int R=points[0][1],res=1;
        for(int i=1;i<points.size();i++){
            int l=points[i][0],r=points[i][1];
            if(l>R){
                res++;
                R=r;
            }
            R=min(r,R);
        }
        return res;
    }
};
//dp--------TLE
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(points.begin(),points.end(),cmp);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(points[i][0]>points[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};
//贪心+二分
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),len=0;
        auto cmp=[](auto &i,auto &j){return i[0]<j[0]||i[0]==j[0]&&i[1]<j[1];};
        sort(points.begin(),points.end(),cmp);
        vector<int> help(n);
        help[0]=points[0][1];
        for(int i=1;i<n;i++){
            int k=lower_bound(help.begin(),help.begin()+len+1,points[i][0])-help.begin();
            if(k>len||help[k]>points[i][1]){
                help[k]=points[i][1];
            }
            len=max(len,k);
        }
        return len+1;
    }
};
/* 
给定由 n 个小写字母字符串组成的数组 strs ，其中每个字符串长度相等。

选取一个删除索引序列，对于 strs 中的每个字符串，删除对应每个索引处的字符。

比如，有 strs = ["abcdef","uvwxyz"] ，删除索引序列 {0, 2, 3} ，删除后为 ["bef", "vyz"] 。

假设，我们选择了一组删除索引 answer ，那么在执行删除操作之后，最终得到的数组的行中的 每个元素 都是按字典序排列的（即 (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]) 和 (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]) ，依此类推）。

请返回 answer.length 的最小可能值 。
960
 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

    }
};
//最大子数组和-------------------------------------------------------------
/* 
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
53
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),res=nums[0];
        vector<int> dp=nums;
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i],dp[i-1]+nums[i]);
            res=max(res,dp[i]);
        }
        return res;
    }
};
/* 
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。
152
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minn=nums[0],maxn=nums[0],n=nums.size(),res=nums[0];
        for(int i=1;i<n;i++){
            int m1=max(nums[i],max(maxn*nums[i],minn*nums[i]));
            int m2=min(nums[i],min(maxn*nums[i],minn*nums[i]));
            maxn=m1,minn=m2;
            res=max(maxn,res);
        }
        return res;
    }
};
/* 
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。
换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，
然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。
1186
 */
//[11,-10,-11,8,7,-6,9,4,11,6,5,0]
//假设已经删除过了
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size(),del=0,res=arr[0];
        //M为未删元素的最大值，m为删除一个元素的最大值
        int M=arr[0],m=arr[0];
        for(int i=1;i<n;i++){
            //删除一个元素后最大值可能为：不删除元素的最大值、删除自身的最大值、删除前面元素的最大值
            m=max(max(arr[i],M+arr[i]),max(M,m+arr[i]));
            M=max(arr[i],M+arr[i]);
            if(arr[i]<del){
                del=arr[i];
            }    
            //cout<<M<<" "<<m<<endl;                                                 
            res=max(max(M,m),res);
        }
        return res;
    }
};

/* 
给定一个整数数组 arr 和一个整数 k ，通过重复 k 次来修改数组。

例如，如果 arr = [1, 2] ， k = 3 ，那么修改后的数组将是 [1, 2, 1, 2, 1, 2] 。

返回修改后的数组中的最大的子数组之和。注意，子数组长度可以是 0，在这种情况下它的总和也是 0。

由于 结果可能会很大，需要返回的 109 + 7 的 模 。
1191**********************************
 */
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        int res=0,n=arr.size();
        int maxn=0,m=0;
        for(int i=0;i<n*2;i++){
            m=max(m+arr[i%n],arr[i%n]);
            maxn=max(maxn,m);
            if(i==n-1&&k==1){
                return maxn;
            }
        }
        if(sum<0){
            return maxn;
        }
        if(maxn==0){
            return 0;
        }
        return ((long long)(k-2)*sum+maxn)%1000000007;
    }
};
/* 
给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
918
 */
//两重循环--超时！
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res=nums[0];
        for(int i=0;i<nums.size();i++){
            int maxn=nums[i];
            for(int j=1;j<nums.size();j++){
                maxn=max(nums[(j+i)%nums.size()],maxn+nums[(j+i)%nums.size()]);
                res=max(res,maxn);
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxn=nums[0],minn=nums[0],M=maxn,m=minn;
        for(int i=1;i<nums.size();i++){
            maxn=max(nums[i],maxn+nums[i]);
            minn=min(nums[i],minn+nums[i]);
            M=max(maxn,M);
            m=min(minn,m);
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum==m){
            return M;
        }
        return max(M,sum-m);
    }
};
//以下两题是结合了前缀和的，与其说动态规划，不如说跟前缀和的模板更像
/* 
给定一个正整数、负整数和 0 组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

注意：本题相对书上原题稍作改动

面试题 17.24. 最大子矩阵
 */
/* 
[9,-8,1,3,-2]
[-3,7,6,-2,4]
[6,-4,-4,8,-7]
 */
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),maxn=INT_MIN;
        int temp[n];
        vector<int> res(4);
        for(int i=0;i<m;i++){
            memset(temp,0,sizeof(temp));
            for(int k=i;k<m;k++){
                int c=0,M=0;
                for(int j=0;j<n;j++){
                    temp[j]+=matrix[k][j];
                    if(M<0){
                        M=temp[j];
                        c=j;
                    }else{
                        M+=temp[j];
                    }
                    if(M>maxn){
                        res[0]=k,res[1]=c,res[2]=i,res[3]=j;
                        maxn=M;
                    }
                }
            }
        }
        return res;
    }
};
/* 
给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。

题目数据保证总会存在一个数值和不超过 k 的矩形区域。
363
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int dest) {
        int m=matrix.size(),n=matrix[0].size();
        int presum[m][n];
        memset(presum,0,sizeof(presum));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i!=0){
                    presum[i][j]=presum[i-1][j];
                }
                presum[i][j]+=matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int k=i;k<m;k++){
                set<int> st;
                st.emplace(0);
                int now=0;
                for(int j=0;j<n;j++){
                    now+=presum[k][j]-((i==0)?0:presum[i-1][j]);
                    //cout<<now<<endl;
                    auto itr=st.lower_bound(now-dest);
                    if(now-*itr<=dest){
                        ans=max(ans,now-*itr);
                    }
                    if(ans==dest){
                        return dest;
                    }
                    st.emplace(now);
                }
            }
        }
        return ans;
    }
};