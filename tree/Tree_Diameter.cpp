#include<bits/stdc++.h>
using namespace std;

class Tree {
public:
    int data;
    vector<Tree*> neighbors;

    Tree(int val) {
        data = val;
    }
};

// Function to calculate height and update maxDiameter
int findHeight(Tree* root, Tree* parent, int& maxDiameter) {
    if (!root) return 0;

    int lh = 0, rh = 0;

    for (auto child : root->neighbors) {
        if (child == parent) continue; // Skip the parent node
        int childHeight = findHeight(child, root, maxDiameter);
        if (childHeight > lh) {
            rh = lh;
            lh = childHeight;
        } else if (childHeight > rh) {
            rh = childHeight;
        }
    }

    // Update the maximum diameter
    maxDiameter = max(maxDiameter, 1 + lh + rh);

    return 1 + lh;
}

int main() {
    int n;
    cin >> n;
    map<int, Tree*> mp;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        Tree* uNode;
        Tree* vNode;

        if (mp.find(u) == mp.end()) {
            uNode = new Tree(u);
            mp[u] = uNode;
        } else {
            uNode = mp[u];
        }

        if (mp.find(v) == mp.end()) {
            vNode = new Tree(v);
            mp[v] = vNode;
        } else {
            vNode = mp[v];
        }

        // Make the graph bidirectional
        uNode->neighbors.push_back(vNode);
        vNode->neighbors.push_back(uNode);
    }

    // Start traversal from any node (e.g., mp[1])
    int diameter = 1;
    findHeight(mp[1], nullptr, diameter);
    cout << diameter - 1<< endl;

    // Free allocated memory
    for (auto& node : mp) {
        delete node.second;
    }

    return 0;
}
