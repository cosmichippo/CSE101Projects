//
// Created by Juan-Fernando Prado Morales on 5/27/21.
//

#include "BinarySearchTree.h"
#include <iostream>

template <class KeyType, class ValueType>
BinarySearchTree<KeyType, ValueType>::BinarySearchTree() {
    root = new TreeNode<KeyType, ValueType>();
}

template <class KeyType, class ValueType>
const TreeNode<KeyType, ValueType>* BinarySearchTree<KeyType, ValueType>::findRoot() {
    return root;
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::addRoot(KeyType key, ValueType value) {
    //std::cout << "test2" << std::endl;
    TreeNode<KeyType, ValueType>* temp = new TreeNode<KeyType, ValueType>();
    temp->key = key; temp->value = value;
    //std::cout << "test3" << std::endl;

    //if (root != nullptr){
    temp->left = root->left;
    temp->right = root->right;
    if(root->left != nullptr)
        root->left->parent = temp;
    if(root->right != nullptr)
        root->right->parent = temp;
    delete root;
    //}

    root = temp;
    calculate_height(root);
    calculate_subtree(root);
    //std::cout << "test4" << std::endl;

    count++;
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::destroy(TreeNode<KeyType, ValueType>*t) {
    if(t == nullptr)
        return;
    destroy(t->left);
    destroy(t->right);
    delete t;
}

template <class KeyType, class ValueType>
TreeNode<KeyType, ValueType>* BinarySearchTree<KeyType, ValueType>::insert_helper(TreeNode<KeyType, ValueType>* node, KeyType K, ValueType V){
        //std::cout << "insert ran" << std::endl; 
        if (node->key > K) {
            if (node->left == nullptr) {
                count++;
                node->left = new TreeNode<KeyType, ValueType>();
                node->left->key = K;
                node->left->value = V;
                node->left->parent = node;
                //calculate_height(node->left);
                return node->left;
            } else {
                return insert_helper(node->left, K, V);
            }   
        }
        if (node->key < K) {
            if (node->right == nullptr) {
                count++;
                node->right = new TreeNode<KeyType, ValueType>();
                node->right->key = K;
                node->right->value = V;
                node->right->parent = node;
                //calculate_height(node->right);
                return node->right;
            } else {
                return insert_helper(node->right, K, V);
            }
        }
        return nullptr;
        //calculate_height_recursive(node);
}
template<class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::insert(KeyType key, ValueType value){
      TreeNode<KeyType, ValueType>* test = insert_helper(root, key, value);
      //std::cout << "poo" << std::endl;
      if (test != nullptr){
        recursive_update(test);
      }
    }

template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::min_key() {
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos->left != nullptr){
        pos = pos->left;
    }
    return pos->key;
}

template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::max_key(){
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos->right != nullptr){
        pos = pos->right;
    }
    return pos->key;
}

template <class KeyType, class ValueType>
TreeNode<KeyType, ValueType>* BinarySearchTree<KeyType, ValueType>::search(KeyType key){
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos != nullptr){
        if(pos->key < key){
            pos = pos->right;
        }
        else if(key < pos->key){
            pos = pos->left;
        }else{
            return pos;
        }
    }
    return nullptr;
}


template <class KeyType, class ValueType>
long BinarySearchTree<KeyType, ValueType>::range(TreeNode<KeyType, ValueType>* node, KeyType low, KeyType high){
  if (node == nullptr){
    return 0;
  }
  if (node->key < low){
    return range(node->right, low, high);
  }
  if(node->key > high){
    return range(node->left, low, high);
  }
  //if (node->key >= low && node->key <= high){
  return 1 + range_only_low(node->left, low) + range_only_high(node->right, high);
  
}

template<class KeyType, class ValueType>
long BinarySearchTree<KeyType, ValueType>::range_only_low(TreeNode<KeyType, ValueType>* node, KeyType low){
  if(node == nullptr) return 0;

  if(node->key >= low){
    if(node->right != nullptr){
      return 1 + range_only_low(node->left, low) + node->right->subtree_size + 1;
      // return node + range_only_low(node->left) + node->right subtree size + node->right;
    }
    return range_only_low(node->left, low) + 1;
    // return node + range_only_low
  }
  else{
    return range_only_low(node->right, low);
  }
}

template<class KeyType, class ValueType>
long BinarySearchTree<KeyType, ValueType>::range_only_high(TreeNode<KeyType, ValueType>* node, KeyType high){
  if(node == nullptr) return 0;

  if(node->key <= high){
    if (node->left != nullptr){
      return 1 + range_only_high(node->right, high) + node->left->subtree_size + 1;
    }
    return range_only_high(node->right, high) + 1;
  }
  else{
    return range_only_high(node->left, high);
  }
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::preorder(TreeNode<KeyType, ValueType>* n){
    std::cout << n->key;
    if (n->left != nullptr){
        std::cout << ' ';
        preorder(n->left);
    }
    
    if(n->right != nullptr){
        std::cout << ' ';
        preorder(n->right);
    }
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::postorder(TreeNode<KeyType, ValueType>* n){
    if (n == nullptr){
        std::cout << "N ";
        return;
    }
    postorder(n->left);
    postorder(n->right);
    KeyType i;

    if (n-> parent != nullptr)
      i = n->parent->key;
    std::cout << "["<<n->key << "," << n->subtree_size <<"]" << "-> "<< i << ' ';
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::inorder(TreeNode<KeyType, ValueType>* n){
    if (n == nullptr)
        return;
    inorder(n->left);
    std::cout << n->key << ' ';
    if (n == nullptr)
        return;
    inorder(n->right);
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::rotate_left(TreeNode<KeyType, ValueType>* top, TreeNode<KeyType, ValueType>* bottom){
        //node top starts on top, but ends up on the bottom. Node bottom starts on the bottom, ends up on top

        TreeNode<KeyType,ValueType>* freed = bottom->left; //node which will be free
        TreeNode<KeyType, ValueType>* parent = top->parent; //tops parent
        //freed = nullptr, parent->5
        bottom->left = top;
        top->parent = bottom; //first node assignment
        top->right = freed; //nullptr
        if (freed != nullptr){
            freed->parent = top;
        }
        bottom->parent = parent; //assign bottom's parent to be top's old parent;

        if (parent != nullptr){
            if(parent->right == top){ //Now, we determine whether parent left or right has to be reassigned.
                parent->right = bottom;
            }else{
                parent->left = bottom;
            }
        }
        
        if (top == this->get_root()){
            this->root = bottom;
        }
    }


template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::rotate_right(TreeNode<KeyType, ValueType>* top, TreeNode<KeyType, ValueType>* bottom){
        //node top starts on top, but ends up on the bottom. Node bottom starts on the bottom, ends up on top

        TreeNode<KeyType,ValueType>* freed = bottom->right; //node which will be free
        TreeNode<KeyType, ValueType>* parent = top->parent; //tops parent

        bottom->right = top;
        top->parent = bottom; //first node assignment

        top->left = freed;
        if (freed != nullptr){
            freed->parent = top;
        }
        bottom->parent = parent; //assign bottom's parent to be top's old parent;

        if (parent != nullptr){
            if(parent->left == top){ //Now, we determine whether parent left or right has to be reassigned.
                parent->left = bottom;
            }else{
                parent->right = bottom;
            }
        }
        
        if (top == this->get_root()){
            this->root = bottom;
    }
}

//no possible segfault (if node != nullptr)
template<class K, class V>
void calculate_height(TreeNode<K, V>* node){ //note - only calculates height of one node.
    if(node->left == nullptr && node->right == nullptr)
        node->height = 1;
    else{
        if(node->left == nullptr){
            node->height = node->right->height + 1;
        }
        else if(node->right == nullptr){
            node->height = node->left->height + 1;
        }
        else{
            if (node->right->height > node->left->height){
                node->height = node->right->height + 1;
            }
            else{
                node->height = node->left->height + 1;
            }
        }
    }
}
template <class K, class V>
void calculate_subtree(TreeNode<K, V>* node){
  if(node->left== nullptr && node-> right == nullptr) node->subtree_size = 0;
  else{
    node->subtree_size = 0;
    if(node->left != nullptr){
      node->subtree_size += node->left->subtree_size + 1;
    }
    if (node->right != nullptr){
      node->subtree_size += node->right->subtree_size + 1;
    }
  }
}


//no possible segfault(if node != nullptr)
template<class K, class V>
int check_heights(TreeNode<K, V>* node){
  int left = 0;
  int right = 0;
  if (node->left != nullptr)
    left = node->left->height;
  if (node->right != nullptr)
    right = node->right->height;
  return left - right;
}


template<class K, class V>
void calculate_height_recursive(TreeNode<K, V>* node){ //note - only calculates height of one node.
  calculate_height(node);
  if(node->parent != nullptr)
    calculate_height_recursive(node->parent);
}

template<class KeyType, class ValueType> //recursively updates the heights of the nodes. 
void BinarySearchTree<KeyType, ValueType>::recursive_update(TreeNode<KeyType, ValueType>* node){ //node = 6
  TreeNode<KeyType, ValueType>* pivot = node->parent; //node->parent 
  calculate_height(node); //node->h = 1
  calculate_subtree(node);
  int i = check_heights(node); // 0
  int j;
  if(i > 1){ // if left is greater than 2
    j = check_heights(node->left);
    pivot = node;
    if (j < 0){
      pivot = node->left;
      rotate_left(pivot, pivot->right); // must rotate_left()
      calculate_height(pivot); //recalculates height at node->left, since it is now shifted down;
      calculate_subtree(pivot);
      pivot = node;
    }
    rotate_right(node, node->left);
  }
  if (i < -1){
    j = check_heights(node->right); // -1
    pivot = node;
    if (j > 0){
      pivot = node->right;
      rotate_right(pivot, pivot->left);
      calculate_height(pivot);
      calculate_subtree(pivot);
      pivot = node;
    }
    rotate_left(node, node->right);
  }
  if(pivot != nullptr){
    recursive_update(pivot);
  }
}