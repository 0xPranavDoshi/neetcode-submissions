class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();

        vector<vector<string>> wordsInLine;
        
        int line_count = 0;
        int word_count = 0;
        unordered_map<int, int> lettersInLine;

        while (word_count <= n-1) {
            int line_size = 0;
            wordsInLine.push_back({});

            if (words[word_count].size() == maxWidth) {
                wordsInLine[line_count].push_back(words[word_count]);
                word_count++;
                lettersInLine[line_count] = maxWidth;
                line_count++;                
                continue;
            }

            wordsInLine[line_count].push_back(words[word_count]);
            line_size += words[word_count].size() + 1;
            lettersInLine[line_count] += words[word_count].size();
            word_count++;

            while (line_size < maxWidth) {
                int remaining = maxWidth - line_size;
                if (word_count <= n-1 && words[word_count].size() <= remaining) {
                    wordsInLine[line_count].push_back(words[word_count]);   
                    line_size += words[word_count].size() + 1;
                    lettersInLine[line_count] += words[word_count].size();
                    word_count++;
                } else {                    
                    line_size++;                                        
                }
            }   

            line_count++;           
        }

        for (int i = 0; i < line_count; i++) {
            for (int j = 0; j < wordsInLine[i].size(); j++) {
                cout << wordsInLine[i][j] << " ";
            }
            cout << "\n";
        }

        vector<string> out(line_count, "");

        for (int i = 0; i < line_count; i++) {
            // cout << "\nLine " << i << ":\n";

            if (wordsInLine[i].size() == 1) {
                // left align and continue
                out[i] += wordsInLine[i][0];
                while (out[i].size() < maxWidth) out[i] += " ";
                continue;
            }

            if (i == line_count - 1) {
                // left align and continue
                for (int j = 0; j < wordsInLine[i].size(); j++) {
                    out[i] += wordsInLine[i][j];
                    if (out[i].size() < maxWidth) out[i] += " ";
                }                
                while (out[i].size() < maxWidth) out[i] += " ";
                continue;
            }

            int gaps = wordsInLine[i].size() - 1;
            int totalSpaces = maxWidth - lettersInLine[i];
            int spacesBetween = totalSpaces / gaps;
            int extraSpaces = totalSpaces % gaps;

            // cout << "Total Spaces: " << totalSpaces << "\n";
            // cout << "Spaces in between: " << spacesBetween << "\n";
            // cout << "Extra Spaces: " << extraSpaces << "\n";

            for (int j = 0; j < wordsInLine[i].size() - 1; j++) {
                out[i] += wordsInLine[i][j];
                for (int k = 0; k < spacesBetween; k++) {
                    out[i] += " ";
                }
                if (extraSpaces > 0) {
                    out[i] += " ";
                    extraSpaces--;
                }
            }
            out[i] += wordsInLine[i][wordsInLine[i].size() - 1];
        }

        return out;
    }
};