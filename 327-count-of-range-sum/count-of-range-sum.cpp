class Solution
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        return mergeSort(prefix, 0, n + 1, lower, upper);
    }

    int mergeSort(vector<long>& pre, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(pre, left, mid, lower, upper) +
                    mergeSort(pre, mid, right, lower, upper);

        int j = mid, k = mid;
        for (int i = left; i < mid; ++i) {
            while (k < right && pre[k] - pre[i] < lower) ++k;
            while (j < right && pre[j] - pre[i] <= upper) ++j;
            count += j - k;
        }

        inplace_merge(pre.begin() + left, pre.begin() + mid, pre.begin() + right);
        return count;
    }

};