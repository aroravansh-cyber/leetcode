int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int n, int target) {
    qsort(nums, n, sizeof(int), compare);
    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int low = i + 1, high = n - 1;

        while (low < high) {
            int curr = nums[i] + nums[low] + nums[high];

            if (abs(curr - target) < abs(ans - target))
                ans = curr;

            if (curr < target)
                low++;
            else if (curr > target)
                high--;
            else
                return curr;
        }
    }
    return ans;
}