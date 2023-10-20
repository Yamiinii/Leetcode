/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    private:
    vector<int> finallist;
    int index;
    vector<int> flatten(vector<NestedInteger> &nestedList)
    {
        vector<int> result;
        int n=nestedList.size();
        for(int i=0;i<n;i++)
        {
            if(nestedList[i].isInteger()){
            result.push_back(nestedList[i].getInteger());
            }
            else
            {
                auto subList = flatten(nestedList[i].getList());
                result.insert(result.end(),subList.begin(),subList.end());
            }
            
        }
        return result;
        
    }
public:
    
    NestedIterator(vector<NestedInteger> &nestedList) {
       finallist=flatten(nestedList);
        index=0;
    }
    
    int next() {
        return finallist[index++];
    }
    
    bool hasNext() {
        return index<finallist.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */