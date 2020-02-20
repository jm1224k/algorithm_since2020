#include <iostream>
#define null 0

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode{
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree{
private:
    TreeNode<T>* root;
public:
    //Tree를 새롭게 생성
    Tree(T data = 0){
        root = new TreeNode<T>(data);
    }
    //build Tree
    void insert_node(TreeNode<T>* current, T n){
        if(current == null){
            current = new TreeNode<T>(n);
        }
        else if(n < current->data){
            if(current->left == null){
                current->left = new TreeNode<T>(n);
            }
            else{
                insert_node(current->left, n);
            }
        }
        else if(n > current->data){
            if(current->right == null){
                current->right = new TreeNode<T>(n);
            }
            else{
                insert_node(current->right, n);
            }
        }
    }
    //get root node
    TreeNode<T>* getRoot(){
        return root;
    }
    //print visit node
    void visit(TreeNode<T>* current) {
        cout << current->data << endl;
    }
    //preorder
    void preorder(TreeNode<T>* current){
        if(current != null) {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }
    //inoreder
    void inorder(TreeNode<T>* current){
        if(current != null) {
            visit(current);
            inorder(current->left);
            inorder(current->right);
        }
    }
    //postorder
    void postorder(TreeNode<T>* current){
        if(current != null) {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }
};

int main(void){
    int tmp = 0;
    scanf("%d", &tmp);
    //build tree
    Tree<int> tree(tmp);
    while(scanf("%d", &tmp)){
        tree.insert_node(tree.getRoot(), tmp);
    }
    //print tree
    tree.postorder(tree.getRoot());
}
