// id = 42280602
#include <iostream>

template <typename T>
class AVLTree {
 public:
  struct Node {
    Node* left;
    Node* right;
    T key;
    int height;
  };
  AVLTree() {
    root_ = nullptr;
  }
  void Insert(T key);
  void Delete(T key);
  void PrintKthStatistic(int k);

 private:
  static int Height(Node* node);
  void FixHeight(Node*& node);
  Node* NewNode(T key);
  static int GetBalance(Node* node);
  Node* RightRotate(Node* old_root);
  Node* LeftRotate(Node* old_root);
  Node* InsertNode(Node* node, T key);
  Node* MinValueNode(Node* node);
  Node* DeleteNode(Node* root, T key);
  Node* KthOrderStatistic(Node* root, int& k);
  Node* root_{ nullptr };
};

template <typename T>
int AVLTree<T>::Height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

template <typename T>
void AVLTree<T>::FixHeight(Node*& node) {
  node->height = std::max(Height(node->left), Height(node->right)) + 1;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::NewNode(T key) {
  auto node = new Node{ nullptr, nullptr, key, 1 };
  return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::RightRotate(Node* old_root) {
  Node* new_root = old_root->left;
  Node* mid_tree = new_root->right;

  new_root->right = old_root;
  old_root->left = mid_tree;

  FixHeight(old_root);
  FixHeight(new_root);

  return new_root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::LeftRotate(Node* old_root) {
  Node* new_root = old_root->right;
  Node* mid_tree = new_root->left;

  new_root->left = old_root;
  old_root->right = mid_tree;

  FixHeight(old_root);
  FixHeight(new_root);

  return new_root;
}

template <typename T>
int AVLTree<T>::GetBalance(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return Height(node->left) - Height(node->right);
}

template <typename T>
void AVLTree<T>::Insert(T key) {
  root_ = InsertNode(root_, key);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::InsertNode(Node* node, T key) {
  if (node == nullptr) {
    return NewNode(key);
  }

  if (key < node->key) {
    node->left = InsertNode(node->left, key);
  }
  else {
    node->right = InsertNode(node->right, key);
  }

  FixHeight(node);

  int balance = GetBalance(node);
  if (balance > 1 && key < node->left->key) {
    return RightRotate(node);
  }
  if (balance < -1 && key > node->right->key) {
    return LeftRotate(node);
  }
  if (balance > 1 && key > node->left->key) {
    node->left = LeftRotate(node->left);
    return RightRotate(node);
  }
  if (balance < -1 && key < node->right->key) {
    node->right = RightRotate(node->right);
    return LeftRotate(node);
  }

  return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::MinValueNode(Node* node) {
  Node* current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <typename T>
void AVLTree<T>::Delete(T key) {
  root_ = DeleteNode(root_, key);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::DeleteNode(Node* root, T key) {
  if (root == nullptr) {
    return root;
  }

  if (key < root->key) {
    root->left = DeleteNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = DeleteNode(root->right, key);
  }
  else {
    if (root->left == nullptr || root->right == nullptr) {
      Node* temp = root->left ? root->left : root->right;
      if (temp == nullptr) {
        root = nullptr;
      }
      else {
        *root = *temp;
      }
    }
    else {
      Node* temp = MinValueNode(root->right);
      root->key = temp->key;
      root->right = DeleteNode(root->right, temp->key);
    }
  }

  if (root == nullptr) {
    return root;
  }

  FixHeight(root);

  int balance = GetBalance(root);
  if (balance > 1 && GetBalance(root->left) >= 0) {
    return RightRotate(root);
  }
  if (balance > 1 && GetBalance(root->left) < 0) {
    root->left = LeftRotate(root->left);
    return RightRotate(root);
  }
  if (balance < -1 && GetBalance(root->right) <= 0) {
    return LeftRotate(root);
  }
  if (balance < -1 && GetBalance(root->right) > 0) {
    root->right = RightRotate(root->right);
    return LeftRotate(root);
  }

  return root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::KthOrderStatistic(Node* root, int& k) {
  if (root == nullptr) {
    return nullptr;
  }

  Node* left = KthOrderStatistic(root->left, k);
  if (left != nullptr) {
    return left;
  }

  --k;
  if (k == 0) {
    return root;
  }
  return KthOrderStatistic(root->right, k);
}

template <typename T>
void AVLTree<T>::PrintKthStatistic(int k) {
  std::cout << KthOrderStatistic(root_, k)->key << std::endl;
}


int main() {
  int n = 0;
  std::cin >> n;
  AVLTree<int> avl;
  int number = 0;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> number >> k;
    if (number > 0) {
      avl.Insert(number);
    }
    else {
      avl.Delete(-number);
    }
    avl.PrintKthStatistic(k + 1);
  }
  return 0;
}
