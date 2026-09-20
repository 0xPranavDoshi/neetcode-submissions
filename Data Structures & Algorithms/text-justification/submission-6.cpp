class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // Find the words that belong in each line
        vector<vector<string>> wordsInLine;

        int line_count = 0;
        int word_count = 0;
        
        while (word_count < words.size()) {
            wordsInLine.push_back({});
            int line_size = 0;

            // If the word takes the whole line, then just use that and continue
            if (words[word_count].size() >= maxWidth - 1) {
                wordsInLine[line_count].push_back(words[word_count]);
                line_count++;                
                word_count++;
                continue;
            }
            
            while (line_size + words[word_count].size() <= maxWidth) {
                line_size += words[word_count].size() + 1;
                wordsInLine[line_count].push_back(words[word_count]);
                word_count++;

                if (word_count >= words.size()) break;
            }            

            line_count++;
        }

        int lines = wordsInLine.size();

        // for (int l = 0; l < lines; l++) {
        //     cout << "Line " << l << "\n";
        //     for (string word : wordsInLine[l]) {
        //         cout << word << " ";
        //     }
        //     cout << "\n\n";
        // }

        vector<int> charsInLine(lines, 0);

        // Calculate the number of characters in each line
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < wordsInLine[i].size(); j++) {
                charsInLine[i] += wordsInLine[i][j].size();
            }
        }

        vector<string> out(lines, "");

        for (int i = 0; i < lines; i++) {
            int word_count = wordsInLine[i].size();
            int char_count = charsInLine[i];

            if (word_count == 1 || i == lines - 1) {
                // Left align
                for (int j = 0; j < wordsInLine[i].size() - 1; j++) {
                    out[i] += (wordsInLine[i][j] + " ");
                }
                out[i] += wordsInLine[i][wordsInLine[i].size() - 1];

                while (out[i].size() < maxWidth) {
                    out[i] += " ";
                }

                continue;
            }

            int spaces = maxWidth - char_count;
            int gaps = word_count - 1;

            int spaces_per_gap = spaces / gaps;
            int extra_spaces = spaces % gaps;            

            for (int j = 0; j < wordsInLine[i].size() - 1; j++) {
                // Add word
                out[i] += wordsInLine[i][j];

                // Add spaces
                for (int k = 0; k < spaces_per_gap; k++) {
                    out[i] += " ";
                }

                // Add extra spaces
                if (extra_spaces > 0) {
                    out[i] += " ";
                    extra_spaces--;
                }
            }

            out[i] += wordsInLine[i][wordsInLine[i].size() - 1];
        }

        return out;
    }
};