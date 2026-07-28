class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();

                int eval = evalExp(t, n2, n1);
                s.push(eval);
            } else {
                s.push(stoi(t));
            }        
        }

        return s.top();
    }

    int evalExp(string op, int n1, int n2) {
        if (op == "+") return n1 + n2;
        else if (op == "-") return n1 - n2;
        else if (op == "*") return n1 * n2;
        else if (op == "/") return n1 / n2;
        else return 0;
    }
};
