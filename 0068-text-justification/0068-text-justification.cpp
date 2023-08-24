class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justified;
        vector<string> wordsline;
        int width = 0;
        int spacing, remainder;
        for (int k = 0; k < words.size(); k++) {
            // Greedy
            width += words[k].size();
            if (width > maxWidth - wordsline.size()) {
                width -= words[k].size();
                if (wordsline.size() == 1) {
                    spacing = -1;
                }
                else {
                    spacing = (maxWidth - width) / (wordsline.size() - 1);
                    remainder = (maxWidth - width) % (wordsline.size() - 1);
                }
                cout << "Line:\t" << width << "/" << maxWidth << " " << spacing << "R" << remainder << "\n";
                stringstream ss;
                width = maxWidth;
                for (int k = 0; k < wordsline.size(); k++) {
                    if (k) {
                        ss << string(spacing, ' ');
                        width -= spacing;
                        if (remainder) {
                            ss << ' ';
                            remainder--;
                            width--;
                        }
                    }
                    ss << wordsline[k];
                    width -= wordsline[k].size();
                }
                ss << string(width, ' ');
                justified.push_back(ss.str());
                cout << ss.str() << "\n\n";
                wordsline.clear();
                width = 0;
                k--;
            }
            else {
                wordsline.push_back(words[k]);
            }
        }
        // Last line
        cout << "Last:\t" << width << "/" << maxWidth << " " << spacing << "R" << remainder << "\n";
        stringstream ss;
        width = maxWidth;
        for (int k = 0; k < wordsline.size(); k++) {
            if (k) {
                ss << " ";
                width--;
            }
            ss << wordsline[k];
            width -= wordsline[k].size();
        }
        ss << string(width, ' ');
        justified.push_back(ss.str());
        cout << ss.str() << "\n\n";
        
        return justified;
    }
};