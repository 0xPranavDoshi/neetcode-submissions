/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> oldToCloned;
        queue<Node*> q;        

        oldToCloned[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            vector<Node*> neighbors = current->neighbors;
            for (Node* n : neighbors) {
                if (oldToCloned.find(n) == oldToCloned.end()) {
                    oldToCloned[n] = new Node(n->val);
                    q.push(n);
                }
                oldToCloned[current]->neighbors.push_back(oldToCloned[n]);                 
            }
        } 

        return oldToCloned[node];
    }
};
