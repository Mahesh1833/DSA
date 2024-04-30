#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        root = new Node;
        root->data = value;
        root->left = root->right = nullptr;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
}

void mirrorTree(Node* root) {
    if (root == nullptr)
        return;
    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recursively mirror left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void displayInOrder(Node* root) {
    if (root != nullptr) {
        displayInOrder(root->left);
        cout << root->data << "->";
        displayInOrder(root->right);
    }
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr;
    int numNodes;
    cout << "Enter the number of nodes to insert: ";
    cin >> numNodes;
    cout << "Enter the values to insert, separated by spaces:\n";
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }
    cout << "Elements in the tree (in-order traversal): ";
    displayInOrder(root);
    cout << "\n";
    int minValue = findMin(root);
    cout << "Minimum data value in the tree: " << minValue << "\n";
    int searchValue;
    cout << "Enter a value to search: ";
    cin >> searchValue;
    if (search(root, searchValue)) {
        cout << "Value " << searchValue << " found in the tree.\n";
    } else {
        cout << "Value " << searchValue << " not found in the tree.\n";
    }
    cout << "Number of nodes in the longest path from the root: " << maxDepth(root) << "\n";
    cout << "Mirroring the tree...\n";
    mirrorTree(root);
    cout << "Elements in the tree after mirroring (in-order traversal): ";
    displayInOrder(root);
    cout << "\n";
    return 0;
}
