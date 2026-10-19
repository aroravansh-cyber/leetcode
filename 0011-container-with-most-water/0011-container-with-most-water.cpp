class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int end = height.size() - 1;
        int result = 0;

        while (front < end) {
            int limit = min(height[front], height[end]);
            int distance = end - front;
            int water = limit * distance;

            if (water > result)
                result = water;

            if (height[front] < height[end])
                front++;
            else
                end--;
        }

        return result;
    }
};
