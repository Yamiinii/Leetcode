/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* tree(vector<vector<int>>& grid,int rowstart,int rowend,int colstart,int colend)
    {
        if(rowstart==rowend && colstart==colend)
        {
            return new Node(grid[rowstart][colstart],true,NULL,NULL,NULL,NULL);
        }
        
       bool isleaf = true;
        int val = grid[rowstart][colstart];
        for (int i = rowstart; i <= rowend; i++) {
            for (int j = colstart; j <= colend; j++) {
                if (grid[i][j] != val) {
                    isleaf = false;
                    break;
                }
            }
            if (!isleaf) break;
        }
        
        if(isleaf)
        {
            return new Node(val,true,NULL,NULL,NULL,NULL);
        }
        
        int rowmid=(rowstart + rowend) / 2;
        int colmid=(colstart+colend)/2;
        Node* TL=tree(grid,rowstart,rowmid,colstart,colmid);
        Node* TR=tree(grid,rowstart,rowmid,colmid+1,colend);
        Node* BL=tree(grid,rowmid+1,rowend,colstart,colmid);
        Node* BR=tree(grid,rowmid+1,rowend,colmid+1,colend);
        
        return new Node(false,false,TL,TR,BL,BR);
        
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
         if (n == 0) return nullptr;
        int m=grid[0].size();
        return tree(grid,0,n-1,0,m-1);
    }
};