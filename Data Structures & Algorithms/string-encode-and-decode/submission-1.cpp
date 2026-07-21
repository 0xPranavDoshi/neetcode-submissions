class Solution {
public:

    string encode(vector<string>& strs) {
        string a;
        for (string s : strs) {
            a += to_string(s.size()) + "#" + s;
        }
        
        cout << a << "\n";
        return a;
    }

    vector<string> decode(string s) {        
        vector<string> a;
        stringstream ss(s);
        string item;

        while (getline(ss, item, '#')) {
            int l = stoi(item);

            string buffer(l, '\0');
            ss.read(&buffer[0], l);
            a.push_back(buffer);
        }

        return a;
    }
};
