#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int>arr;
    void midordered(TreeNode* root)
    {
        if(root)
        {
            midordered(root->left);
            arr.push_back(root->val);
            midordered(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        midordered(root);
        int l = 0, r = arr.size() - 1;
        while(l < r)
        {
            int sum = arr[l] + arr[r];
            if(sum == k) return true;
            if(sum > k) r--;
            else l++;
        }
        return false;
    }
};

int main()
{	
	return 0;
}

