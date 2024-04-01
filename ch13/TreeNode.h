#ifndef __TREE_NODE__
#define __TREE_NODE__

#include <cstddef>
#include <string>

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(std::string &v, int c): value(v), count(c), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode& node);
    ~TreeNode();
    TreeNode& operator=(const TreeNode &);

private:
    std::string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};

class BinStrTree {
public:
    BinStrTree(const TreeNode &r = TreeNode())
        : root(new TreeNode(r)), use(new std::size_t(1)) {}

    BinStrTree(const BinStrTree &);

    ~BinStrTree();

    BinStrTree& operator=(const BinStrTree &);

private:
    TreeNode *root;
    std::size_t *use;
};

#endif // !__TREE_NODE__
