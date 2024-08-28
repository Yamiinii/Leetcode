class Solution {
public:
    Node* tree(vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        // Base case: single cell
        if (rs == re && cs == ce) {
            return new Node(grid[rs][cs] == 1, true);
        }

        // Check if all cells in the current sub-grid have the same value
        bool isLeaf = true;
        int value = grid[rs][cs];
        for (int i = rs; i <= re; ++i) {
            for (int j = cs; j <= ce; ++j) {
                if (grid[i][j] != value) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }

        // If all cells are the same, return a leaf node
        if (isLeaf) {
            return new Node(value == 1, true);
        }

        // Split the grid into four quadrants
        int rm = (rs + re) / 2;
        int cm = (cs + ce) / 2;

        Node* topLeft = tree(grid, rs, rm, cs, cm);
        Node* topRight = tree(grid, rs, rm, cm + 1, ce);
        Node* bottomLeft = tree(grid, rm + 1, re, cs, cm);
        Node* bottomRight = tree(grid, rm + 1, re, cm + 1, ce);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return NULL;
        return tree(grid, 0, n - 1, 0, n - 1);
    }
};
