int cmp(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 100, size = 0;
    int** ans = malloc(cap * sizeof(int*));
    *returnColumnSizes = malloc(cap * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int l = j + 1, r = numsSize - 1;
            while (l < r) {
                long long s = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (s < target) l++;
                else if (s > target) r--;
                else {
                    if (size == cap) {
                        cap *= 2;
                        ans = realloc(ans, cap * sizeof(int*));
                        *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                    }
                    ans[size] = malloc(4 * sizeof(int));
                    ans[size][0] = nums[i];
                    ans[size][1] = nums[j];
                    ans[size][2] = nums[l];
                    ans[size][3] = nums[r];
                    (*returnColumnSizes)[size++] = 4;

                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
    }
    *returnSize = size;
    return ans;
}