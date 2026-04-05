#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Result {
    int sum;
    int start;
    int end;
};


Result maxCrossingSubarray(vector<int>& nums, int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {leftSum + rightSum, maxLeft, maxRight};
}


Result maxSubarray(vector<int>& nums, int left, int right) {
    if (left == right) {
        return {nums[left], left, right};
    }

    int mid = left + (right - left) / 2;

    Result leftRes = maxSubarray(nums, left, mid);
    Result rightRes = maxSubarray(nums, mid + 1, right);
    Result crossRes = maxCrossingSubarray(nums, left, mid, right);

    if (leftRes.sum >= rightRes.sum && leftRes.sum >= crossRes.sum)
        return leftRes;
    else if (rightRes.sum >= leftRes.sum && rightRes.sum >= crossRes.sum)
        return rightRes;
    else
        return crossRes;
}

int main() {
    int n;
    
    cin >> n;

    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Result res = maxSubarray(nums, 0, n - 1);

    cout << "\nSum = " << res.sum << endl;
    cout << "Start Index = " << res.start << endl;
    cout << "End Index = " << res.end << endl;

    return 0;
}