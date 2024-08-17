class Solution {
public:
    string find_line(int i,int j,int eachblankspace,int extrablankspace,vector<string>& words,int maxi)
    {
        string line;
        
        for(int k=i;k<j;k++)
        {
            line+=words[k];
            
            if(k==j-1)
                continue;
            
            for(int z=1;z<=eachblankspace;z++)
                line+=" ";
            
            if(extrablankspace>0)
            {
                line+=" ";
                extrablankspace--;
            }
        }
        
        while(line.length()<maxi)
            line+=" ";
        
        return line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        int n=words.size();
        int maxi=maxWidth;
        while(i<n)
        {
            int lettercnt=words[i].size();
            int space=0;
            int j=i+1;
            while(j<n && words[j].length()+1+lettercnt+space<=maxi)
            {
                lettercnt+=words[j].size();
                space++;
                j++;
            }
            
            int remainingspace=maxi-lettercnt;
            int eachblankspace=space==0?0:remainingspace/space;
            int extrablankspace=space==0?0:remainingspace%space;
            
            if(j==n)
            {
                eachblankspace=1;
                extrablankspace=0;
            }
            
            ans.push_back(find_line(i,j,eachblankspace,extrablankspace,words,maxi));
            
            i=j;
        }
        
        return ans;
    }
};