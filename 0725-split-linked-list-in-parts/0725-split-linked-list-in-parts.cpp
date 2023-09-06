class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* current = head;
        while (current != nullptr) {
            cnt++;
            current = current->next;
        }

        int width = cnt / k; // Minimum number of nodes in each part
        int remainder = cnt % k; // Number of parts that will have one extra node

        vector<ListNode*> result;
        current = head;
        for (int i = 0; i < k; i++) {
            ListNode* part_head = current;
            result.push_back(part_head);

            int part_size = width + (i < remainder ? 1 : 0); // Add 1 to the width for the first 'remainder' parts
            for (int j = 0; j < part_size - 1; j++) {
                current = current->next;
            }

            if (current != nullptr) {
                ListNode* next_node = current->next;
                current->next = nullptr;
                current = next_node;
            }
        }

        return result;
    }
};
