#include <vector>
#include <queue>

class KthLargest {
public:
    int K;  // The k value
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Min-heap

    // Constructor
    KthLargest(int k, std::vector<int>& nums) : K(k) {
        // Insert elements into the min-heap
        for (int num : nums) {
            pq.push(num);
            // Maintain only k largest elements
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    
    // Add a new value and return the k-th largest element
    int add(int val) {
        pq.push(val); // Add the new value
        // Maintain only k largest elements
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top(); // The top of the min-heap is the k-th largest element
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
