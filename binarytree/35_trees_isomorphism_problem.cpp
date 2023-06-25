/*
    Time Complexity:
    The above solution does a traversal of both trees.
    So time complexity is O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.
*/

// A C++ program to check if two given trees are isomorphic
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left and right children */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Given a binary tree, print its nodes in reverse level order */
bool isIsomorphic(node* n1, node* n2)
{
// Both roots are NULL, trees isomorphic by definition
    if (n1 == NULL && n2 == NULL)
        return true;

    // Exactly one of the n1 and n2 is NULL, trees not isomorphic
    if (n1 == NULL || n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    // There are two possible cases for n1 and n2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return
        (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
        (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}
