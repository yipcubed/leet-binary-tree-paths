#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isLeaf(TreeNode *r) {
        return r && !r->left && !r->right;
    }

    void DFS(TreeNode *r, vector<int>& path, vector<vector<int>>& allpaths) {
        if (isLeaf(r)) {
            path.push_back(r->val);
            allpaths.push_back(path);
        }
        if (r->left) {
            vector<int> p(path);
            p.push_back(r->val);
            DFS(r->left, p, allpaths);
        }
        if (r->right) {
            vector<int> p(path);
            p.push_back(r->val);
            DFS(r->right, p, allpaths);
        }
    }

    string vec2str(vector<int>& v) {
        if (v.empty()) return "";
        stringstream ss;
        ss << v[0];
        for (int i = 1; i < v.size(); ++i) {
            ss << "->" << v[i];
        }
        return ss.str();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<vector<int>> allpaths;
        if (!root) return paths;
        vector<int> path;
        DFS(root, path, allpaths);
        for (auto& vi : allpaths) {
            paths.push_back(vec2str(vi));
        }
        return paths;
    }
};

void test1() {
    vector<int> v1{1, 2, 3, -1, 5};
    TreeNode *t1 = new TreeNode(v1, -1);
    cout << t1 << endl;
    cout << "[\"1->2->5\", \"1->3\"] ? " << Solution().binaryTreePaths(t1) << endl;

}

void test2() {

}

void test3() {

}