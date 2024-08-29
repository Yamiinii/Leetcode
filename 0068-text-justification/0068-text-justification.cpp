class Solution {
public:
    string addline(vector<string>& words, int maxWidth,int i,int j,int eachspace,int leftmargin)
    {
        string line;
        
        for(int k=i;k<j;k++)
        {
            line+=words[k];
            if(k==j-1)
                continue;
            
            for(int l=0;l<eachspace;l++)
                line+=" ";
            
            if(leftmargin>0)
            {
                line+=" ";
                leftmargin--;
            }
        }
        while(line.length()<maxWidth)
            line+=" ";
        
        return line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> ans;
        int i=0;
        while(i<n)
        {
            int lettercnt=words[i].size();
            int space=0;
            int j=i+1;
            while(j<n && words[j].size()+1+space+lettercnt<=maxWidth)
            {
                lettercnt+=words[j].size();
                space++;
                j++;
            }
            
            int remain=maxWidth-lettercnt;
            int eachspace=space==0?0:remain/space;
            int leftmargin=space==0?0:remain%space;
            
            if(j==n)
            {
                eachspace=1;
                leftmargin=0;
            }
            ans.push_back(addline(words,maxWidth,i,j,eachspace,leftmargin));
            i=j;
        }
        
        return ans;
    }
};