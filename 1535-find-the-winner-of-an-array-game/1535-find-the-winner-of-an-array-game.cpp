class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int round_count = 0;
        int dip_index = 0;
        int max_element = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > max_element) {
                max_element = arr[i];
                round_count = 1;
            } else {
                round_count++;
            }

            if (round_count == k) {
                return max_element;
            }
        }

        // If no dip element wins k consecutive rounds, the maximum element wins.
        return max_element;
    }
};
