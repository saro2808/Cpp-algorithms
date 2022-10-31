// id = 42265460
#include <cstdlib>
#include <iostream>
#include <queue>

//********    Binary tree    ********//
template <typename T>
class Tree {
 public:
  struct Node {
    Node(T key) : key(key) {
      left = nullptr;
      right = nullptr;
    }

    ~Node() {
      delete left;
      delete right;
    }

    T key;
    Node* left;
    Node* right;
  };

  Tree() {
    root_ = nullptr;
  }

  void Insert(T key);
  int GetMaxLayerWidth();

  ~Tree() {
    delete root_;
  }

 private:
  Node* root_;
};

template <typename T>
void Tree<T>::Insert(T key) {
  auto node_to_append = new Node(key);
  if (root_ == nullptr) {
    root_ = node_to_append;
    return;
  }

  auto current = root_;
  auto next = root_;

  while (next != nullptr) {
    current = next;
    if (key <= current->key) {
      next = next->left;
    }
    else {
      next = next->right;
    }
  }
  if (key <= current->key) {
    current->left = node_to_append;
  }
  else {
    current->right = node_to_append;
  }
}

template <typename T>
int Tree<T>::GetMaxLayerWidth() {
  int max_layer_width = 0;
  std::queue<Node*> layer;
  layer.push(root_);
  while (! layer.empty()) {
    int current_layer_width = layer.size();
    max_layer_width = std::max(max_layer_width, current_layer_width);
    for (int i = 0; i < current_layer_width; ++i) {
      Node* temp = layer.front();
      layer.pop();
      if (temp->left != nullptr) {
        layer.push(temp->left);
      }
      if (temp->right != nullptr) {
        layer.push(temp->right);
      }
    }
  }
  return max_layer_width;
}

//********    Treap    ********//
template <class T, class P>
class Treap {
 public:
  struct Node {
   public:
    Node(T key, P priority) : key(std::move(key)), priority(std::move(priority)) {
      left = nullptr;
      right = nullptr;
    }

    ~Node() {
      delete left;
      delete right;
    }

    T key;
    P priority;
    Node* left;
    Node* right;
  };

  Treap() {
    root_ = nullptr;
  }

  ~Treap() {
    delete root_;
  }

  void Insert(T key, P priority);
  int GetMaxLayerWidth();

 private:
  void Split(Node* current, T key, Node*& left, Node*& right);
  Node* root_;
};

template <typename T, typename P>
void Treap<T, P>::Insert(T key, P priority) {
  auto node_to_append = new Node(key, priority);

  if (root_ == nullptr) {
    root_ = node_to_append;
    return;
  }

  Node* current = root_;
  Node* previous = root_;

  while (current != nullptr && current->priority >= priority) {
    previous = current;
    if (key <= current->key) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }

  Split(current, key, node_to_append->left, node_to_append->right);

  if (current == root_) {
    root_ = node_to_append;
  }
  else {
    if (key <= previous->key) {
      previous->left = node_to_append;
    }
    else {
      previous->right = node_to_append;
    }
  }
}

template <typename T, typename P>
int Treap<T, P>::GetMaxLayerWidth() {
  int max_layer_width = 0;
  std::queue<Node*> layer;
  layer.push(root_);
  while (! layer.empty()) {
    int current_layer_width = layer.size();
    if (current_layer_width > max_layer_width) {
      max_layer_width = current_layer_width;
    }
    for (int i = 0; i < current_layer_width; ++i) {
      Node* temp = layer.front();
      layer.pop();
      if (temp->left) {
        layer.push(temp->left);
      }
      if (temp->right) {
        layer.push(temp->right);
      }
    }
  }
  return max_layer_width;
}

template <typename T, typename P>
void Treap<T, P>::Split(Node* current, T key, Node*& left, Node*& right) {
  if (current == nullptr) {
    left = nullptr;
    right = nullptr;
  }
  else if (current->key <= key) {
    Split(current->right, key, current->right, right);
    left = current;
  }
  else {
    Split(current->left, key, left, current->left);
    right = current;
  }
}


int main() {
  Tree<int> tree;
  Treap<int, int> treap;
  int n = 0;
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    int key = 0;
    int priority = 0;
    std::cin >> key >> priority;
    tree.Insert(key);
    treap.Insert(key, priority);
  }
  std::cout << treap.GetMaxLayerWidth() - tree.GetMaxLayerWidth() << std::endl;
  return 0;
}
