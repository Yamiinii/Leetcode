class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int left = low, right = mid + 1, index = 0;

        while (left <= mid && right <= high) {
            if ((long long)arr[left] <= (long long)arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }

        while (left <= mid) {
            temp[index++] = arr[left++];
        }

        while (right <= high) {
            temp[index++] = arr[right++];
        }

        for (int i = 0; i < temp.size(); ++i) {
            arr[low + i] = temp[i];
        }
    }

    int merge_new(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; ++i) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                ++right;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            cnt += mergeSort(nums, low, mid);
            cnt += mergeSort(nums, mid + 1, high);
            cnt += merge_new(nums, low, mid, high);
            merge(nums, low, mid, high);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
