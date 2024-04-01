#include "TreeNode.h"

TreeNode::TreeNode(const TreeNode& rhs)
    : value(rhs.value), count(rhs.count), left(nullptr), right(nullptr) {
    if(rhs.left) {
        left = new TreeNode(*rhs.left);
    }
    if(rhs.right) {
        left = new TreeNode(*rhs.right);
    }
}

TreeNode& TreeNode::operator=(const TreeNode &rhs) {
    value = rhs.value;
    count = rhs.count;

    TreeNode *temp = nullptr;
    if(rhs.left) {
        temp = new TreeNode(*rhs.left);
    }
    delete left;
    left = temp;

    temp = nullptr;
    if(rhs.right) {
        temp = new TreeNode(*rhs.right);
    }
    delete right;
    right = temp;

    return *this;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

BinStrTree::BinStrTree(const BinStrTree &rhs)
    :root(new TreeNode(*rhs.root)), use(rhs.use){
    ++*use;
}

BinStrTree::~BinStrTree() {
    if(--*use == 0) {
        delete root;
        delete use;
    }
}

BinStrTree& BinStrTree::operator=(const BinStrTree &rhs) {
    ++*rhs.use;
    if(--*use == 0) {
        delete root;
        delete use;
    }

    root = rhs.root;
    use  = rhs.use;

    return *this;
}
