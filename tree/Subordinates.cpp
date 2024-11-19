#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    int data;
    vector<Tree*> neighbors;
    Tree(int val) {
        data = val;
    }
};

// The DFS function calculates the number of subordinates for each employee
int dfs(Tree* root, vector<int>& ans) {
    int total = 0;  // Total subordinates count
    for (auto child : root->neighbors) {
        int subordinates = dfs(child, ans);  // Recursive call
        total += subordinates;               // Accumulate counts
    }
    ans[root->data] = total;  // Store the count in the answer array
    return total + 1;         // Return count including the employee
}

// The createTree function builds the tree and returns the map of nodes
map<int, Tree*> createTree(vector<int>& bosses) {
    map<int, Tree*> mp;
    Tree* root = new Tree(1);
    mp[1] = root;
    for (int i = 0; i < bosses.size(); i++) {
        int boss = bosses[i];
        int employee = i + 2;

        Tree* employeeNode;
        if (mp.find(employee) == mp.end()) {
            employeeNode = new Tree(employee);
            mp[employee] = employeeNode;
        } else {
            employeeNode = mp[employee];
        }

        Tree* bossNode;
        if (mp.find(boss) == mp.end()) {
            bossNode = new Tree(boss);
            mp[boss] = bossNode;
        } else {
            bossNode = mp[boss];
        }
        bossNode->neighbors.push_back(employeeNode);
    }
    return mp;
}

int main() {
    int n;
    cin >> n;
    vector<int> bosses(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> bosses[i];
    }
    map<int, Tree*> mp = createTree(bosses);
    vector<int> ans(n + 1, 0);  // Initialize answer array with zeros
    Tree* root = mp[1];
    dfs(root, ans);
    for (int i = 1; i <= n; i++) {  // Print from index 1 to n
        cout << ans[i] << " ";
    }
    return 0;
}
