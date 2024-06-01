#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
};

Node *makeNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

Node *insert(Node *node, int key) {
  if (node == nullptr) {
    return makeNode(key);
  }
  if (key < node->key) {
    node->left = insert(node->left, key);
  }
  if (key > node->key) {
    node->right = insert(node->right, key);
  }
  return node;
}

void postorder(Node *node) {
  if (node == nullptr)
    return;
  postorder(node->left);
  postorder(node->right);
  cout << node->key << '\n';
}

int main() {
  int n;
  Node *root = nullptr;
  while (cin >> n) {
    if (root == nullptr) {
      root = makeNode(n);
    } else {
      insert(root, n);
    }
  }

  postorder(root);
  return 0;
}