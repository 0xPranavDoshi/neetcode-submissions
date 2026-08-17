class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += (to_string(s.size()) + "#" + s);
        }

        cout << encoded << "\n";
        return encoded;
    }

    vector<string> decode(string s) {
        stringstream ss(s);
        string out;
        vector<string> strs;

        while (getline(ss, out, '#')) {
            cout << "out is " << out << "\n";
            int n = stoi(out);

            string word(n, '\0');
            ss.read(&word[0], n);
            cout << "Read word: " << word << "\n";   
            strs.push_back(word);         
        }
        return strs;
    }
};
