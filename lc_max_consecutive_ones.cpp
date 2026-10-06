#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxConsecutiveOnes(const vector<int>& v, int k)
{
    int left = 0;
    int zeros = 0;
    int maxLength = 0;

    for (int right = 0; right < v.size(); right++)
    {
        // Include v[right] in the window
        if (v[right] == 0)
            zeros++;

        // If we have more than k zeros,
        // move left until the window is valid again
        while (zeros > k)
        {
            if (v[left] == 0)
                zeros--;

            left++;
        }

        // Current window has at most k zeros
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    vector<int> v = {1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    int k = 2;

    int result = maxConsecutiveOnes(v, k);

    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}
