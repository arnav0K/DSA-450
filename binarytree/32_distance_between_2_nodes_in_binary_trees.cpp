Node* LCA(Node* root, int n1, int n2)
{
    // Your code here
    if (root == NULL)
        return root;
    if (root->key == n1 || root->key == n2)
        return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return (left) ? left : right;
}

// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(Node* root, int k, int level)
{
    if (root == NULL) return -1;
    if (root->key == k) return level;

    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}

int findDistance(Node* root, int a, int b)
{
    // Your code here
    Node* lca = LCA(root, a, b);

    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}
 
