// id = 42213114

#include <iostream>
#include <stack>

template <typename T>
class Tree {
 public:
  struct Node {
    Node* left;
    Node* right;
    T value;
    ~Node() {
      delete left;
      delete right;
    }
  };

  void Insert(T value);
  void PrintPreOrder() const;
  ~Tree();

 private:
  static void InsertNode(Node* current_node, Node* new_node);
  static void PrintNonRecursively(Node* node);
  Node* root_{ nullptr };
};

template <typename T>
void Tree<T>::Insert(T value) {
  auto new_node = new Node{ nullptr, nullptr, std::move(value) };
  if (root_ == nullptr) {
    root_ = new_node;
    return;
  }
  InsertNode(root_, new_node);
}

template <typename T>
void Tree<T>::InsertNode(Node* current_node, Node* new_node) {
  while (true) {
    if (new_node->value < current_node->value) {
      if (current_node->left == nullptr) {
        current_node->left = new_node;
        return;
      }
      current_node = current_node->left;
    }
    else {
      if (current_node->right == nullptr) {
        current_node->right = new_node;
        return;
      }
      current_node = current_node->right;
    }
  }
}

template <typename T>
void Tree<T>::PrintPreOrder() const {
  PrintNonRecursively(root_);
}

template <typename T>
void Tree<T>::PrintNonRecursively(Node* node) {
  auto do_stuff = [](Node* node) { std::cout << node->value << " "; };
  std::stack<Node*> st;
  Node* current_node = node;
  while (true) {
    if (current_node == nullptr) {
      while (! st.empty() && current_node == st.top()->right) {
        current_node = st.top();
        st.pop();
      }
      if (st.empty()) {
        return;
      }
      current_node = st.top()->right;
    }
    else {
      // std::cout << current_node->value << " ";
      do_stuff(current_node);
      st.push(current_node);
      current_node = current_node->left;
    }
  }
}

template <typename T>
Tree<T>::~Tree() {
  /*Node* saved = nullptr;
  for (Node* it = root_; it != nullptr; it = saved) {
    if (it->left == nullptr) {
      saved = it->right;
      delete it;
    }
    else {
      saved = it->left;
      it->left = saved->right;
      saved->right = it;
    }
  }*/
  delete root_;
}

int main() {
  Tree<int> tree;
  int n = 0;
  std::cin >> n;
  int current = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> current;
    tree.Insert(current);
  }
  tree.PrintPreOrder();
  std::cout << std::endl;
  return 0;
}
