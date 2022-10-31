// id = 43487178
#include <iostream>
#include <string>
#include <vector>

const int kP = 300007;

unsigned int HashFunction(std::string s, unsigned int table_size) {
  unsigned int hash = s[0] % table_size;
  for (auto item = s.begin() + 1; item != s.end(); ++item) {
    hash = (hash * kP + *item) % table_size;
  }
  return hash;
}

class HashTable {
 public:
  HashTable(int new_size) : table_(new_size), size_(0) {
    for (int i = 0; i < table_.size(); ++i) {
      table_[i] = " ";
    }
  };
  bool Insert(const std::string& s);
  bool Delete(const std::string& s);
  bool Search(const std::string& s);

 private:
  void Expand();
  std::vector<std::string> table_;
  int size_;
};

bool HashTable::Insert(const std::string& s) {
  if (4 * size_ >= table_.size() * 3) {
    Expand();
  }
  unsigned int hash = HashFunction(s, table_.size());
  for (unsigned int i = 0; i < table_.size(); ++i) {
    hash = (hash + i) % table_.size();
    if (table_[hash] == " ") {
      table_[hash] = s;
      break;
    }
    if (table_[hash] == s) {
      return false;
    }
  }
  ++size_;
  return true;
}

bool HashTable::Delete(const std::string& s) {
  unsigned int table_size = table_.size();
  unsigned int hash = HashFunction(s, table_size);
  for (unsigned int i = 0;; ++i) {
    hash = (hash + i) % table_size;
    if (table_[hash] == s) {
      table_[hash] = "DELETED";
      return true;
    }
    if (table_[hash] == " ") {
      return false;
    }
  }
  return false;
}

bool HashTable::Search(const std::string& s) {
  unsigned int table_size = table_.size();
  unsigned int hash = HashFunction(s, table_size);
  for (unsigned int i = 0;; ++i) {
    hash = (hash + i) % table_size;
    if (table_[hash] == s) {
      return true;
    }
    if (table_[hash] == " ") {
      return false;
    }
  }
}

void HashTable::Expand() {
  std::vector<std::string> new_table(table_.size() * 2);
  for (int i = 0; i < new_table.size(); ++i) {
    new_table[i] = " ";
  }
  int new_size = 0;
  for (int i = 0; i < table_.size(); ++i) {
    if (table_[i] != "DELETED" && table_[i] != " ") {
      unsigned int hash = HashFunction(table_[i], new_table.size());
      for (unsigned int j = 0;; ++j) {
        hash = (hash + j) % new_table.size();
        if (new_table[hash] == " ") {
          ++new_size;
          new_table[hash] = table_[i];
          break;
        }
      }
    }
  }
  table_ = new_table;
  size_ = new_size;
}

int main() {
  const int initial_size = 8;
  HashTable hash_table(initial_size);
  std::string operation;
  std::string str;
  while (std::cin >> operation) {
    std::cin >> str;
    if (operation == "+") {
      if (hash_table.Insert(str)) {
        std::cout << "OK" << std::endl;
      }
      else {
        std::cout << "FAIL" << std::endl;
      }
      continue;
    }
    if (operation == "?") {
      if (hash_table.Search(str)) {
        std::cout << "OK" << std::endl;
      }
      else {
        std::cout << "FAIL" << std::endl;
      }
      continue;
    }
    if (hash_table.Delete(str)) {
      std::cout << "OK" << std::endl;
    }
    else {
      std::cout << "FAIL" << std::endl;
    }
  }
}
