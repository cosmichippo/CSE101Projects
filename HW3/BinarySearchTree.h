//
// Created by Juan-Fernando Prado Morales on 5/27/21.
//

#ifndef ASGMT5_BINARYSEARCHTREE_H
#define ASGMT5_BINARYSEARCHTREE_H
#include <queue>

template <class KeyType, class ValueType>
struct TreeNode{
    
    KeyType key;
    int height;
    int subtree_size;
    ValueType value;
    TreeNode<KeyType, ValueType>* parent;
    TreeNode<KeyType, ValueType>* right;
    TreeNode<KeyType, ValueType>* left;
    TreeNode() :key(), value(), parent(nullptr), right(nullptr), left(nullptr){}
};

template <class KeyType, class ValueType>
class BinarySearchTree {
public:
    BinarySearchTree();

    void destroy(TreeNode<KeyType, ValueType>* t);
    ~BinarySearchTree(){destroy(root);}
    TreeNode<KeyType, ValueType>* get_root(){
        return this->root;
    }
    void insert(KeyType key, ValueType value);
    KeyType min_key();

    KeyType max_key();

    TreeNode<KeyType, ValueType>* search(KeyType key);
    const TreeNode<KeyType, ValueType>* findRoot();
    void addRoot(KeyType key, ValueType value);
    void print_inorder() {inorder(root);}
    void print_postorder() {postorder(root);}
    void print_preorder() {preorder(root);}
    long range(TreeNode<KeyType, ValueType>* node, KeyType low, KeyType high);
    long range_only_low(TreeNode<KeyType, ValueType>* node, KeyType low);
    long range_only_high(TreeNode<KeyType, ValueType>* node, KeyType high);
    template<class K, class V>
    friend void calculate_height(TreeNode<K, V>* node);
    template<class K, class V>
    friend void calculate_height_recursive(TreeNode<K, V>* node);
    template<class K, class V>
    friend char check_heights(TreeNode<K, V>* node);
    template<class K, class V>
    friend void calculate_subtree(TreeNode<K, V>* node);
    void rotate_left(TreeNode<KeyType, ValueType>* top, TreeNode<KeyType, ValueType>* bottom);
    void rotate_right(TreeNode<KeyType, ValueType>* top, TreeNode<KeyType, ValueType>* bottom);
    void recursive_update(TreeNode<KeyType, ValueType>* node);
    std::queue<KeyType> propagate(KeyType key);

//private:
    void inorder(TreeNode<KeyType, ValueType>* n);

    void postorder(TreeNode<KeyType, ValueType>* n);

    void preorder(TreeNode<KeyType, ValueType>* n);

    TreeNode<KeyType, ValueType>* insert_helper(TreeNode<KeyType, ValueType>* node, KeyType K, ValueType V);
    
    TreeNode<KeyType, ValueType>* root = nullptr;
    int count = 0;
};


#endif //ASGMT5_BINARYSEARCHTREE_H
