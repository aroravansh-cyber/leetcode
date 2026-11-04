#define MAXV 2000001

int bitCount[MAXV + 1];
long long bitSum[MAXV + 1];

void update(int index, int count, long long sum) {
    while (index <= MAXV) {
        bitCount[index] += count;
        bitSum[index] += sum;
        index += index & -index;
    }
}

int getCount(int index) {
    int result = 0;
    while (index > 0) {
        result += bitCount[index];
        index -= index & -index;
    }
    return result;
}

long long getSum(int index) {
    long long result = 0;
    while (index > 0) {
        result += bitSum[index];
        index -= index & -index;
    }
    return result;
}

int findMedian(int k) {
    int index = 0;

    for (int step = 1 << 20; step > 0; step >>= 1) {
        int next = index + step;

        if (next <= MAXV && bitCount[next] < k) {
            index = next;
            k -= bitCount[next];
        }
    }

    return index + 1;
}

long long minOperations(int* nums, int numsSize, int x, int k) {
    memset(bitCount, 0, sizeof(bitCount));
    memset(bitSum, 0, sizeof(bitSum));

    int windows = numsSize - x + 1;
    long long* cost = malloc(windows * sizeof(long long));
    long long totalSum = 0;

    for (int i = 0; i < x; i++) {
        update(nums[i] + 1000001, 1, nums[i]);
        totalSum += nums[i];
    }

    for (int i = 0; i < windows; i++) {
        int medianIndex = findMedian((x + 1) / 2);
        int median = medianIndex - 1000001;

        int leftCount = getCount(medianIndex);
        long long leftSum = getSum(medianIndex);

        int rightCount = x - leftCount;
        long long rightSum = totalSum - leftSum;

        cost[i] = (long long)median * leftCount - leftSum
                + rightSum - (long long)median * rightCount;

        if (i + 1 < windows) {
            int outgoing = nums[i];
            int incoming = nums[i + x];

            update(outgoing + 1000001, -1, -outgoing);
            update(incoming + 1000001, 1, incoming);

            totalSum += (long long)incoming - outgoing;
        }
    }

    long long INF = LLONG_MAX / 4;
    long long* prev = malloc((numsSize + 1) * sizeof(long long));
    long long* curr = malloc((numsSize + 1) * sizeof(long long));

    for (int i = 0; i <= numsSize; i++) {
        prev[i] = 0;
    }

    for (int j = 1; j <= k; j++) {
        curr[0] = INF;

        for (int i = 1; i <= numsSize; i++) {
            curr[i] = curr[i - 1];

            if (i >= x) {
                int start = i - x;

                if (prev[start] != INF) {
                    long long take = prev[start] + cost[start];

                    if (take < curr[i]) {
                        curr[i] = take;
                    }
                }
            }
        }

        long long* temp = prev;
        prev = curr;
        curr = temp;
    }
    long long answer = prev[numsSize];
    free(cost);
    free(prev);
    free(curr);
    return answer;
}