//#include "TreeNode.hpp"
/*
  Author: Hanan sedaghat pisheh
  Course: CS 315
  Assignment: Lab 4 Part B
*/


// Forward declaration of TreeNode class below.
// Since BinSearchTree uses TreeNode pointers rather
// than objects, we can get away with this in the .hpp.
// You should include "TreeNode.hpp" from the .cpp
class TreeNode;

class BinSearchTree {
public:
  void insert( int v );
  bool find( int v );
  bool iterFind( int v );
  int size();
  void inorderDump();
  int maxDepth();

private:
  TreeNode *local_insert( TreeNode *, int );
  TreeNode *root;
  bool find(TreeNode * root , int v);
  void inorderDump(TreeNode * root);
  int maxDepth(TreeNode * root);
  int size(TreeNode * root); 
};
