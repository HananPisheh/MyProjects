class TreeNode;
class BinSearchTree {
public:
  void insert( int v );
  bool find( int v );
  bool iterFind( int v );
  int size();
  void inorderDump();
  void levelOrderDump();
  bool remove( int v );
  int kthSmallest( int k );
  void valuesAtLevel( int k );
  void iterValuesAtLevel( int k );
  int maxDepth();
  int iterMaxDepth();
  bool hasRootToLeafSum( int sum );
  bool areIdentical( BinSearchTree *bst );
  BinSearchTree *intersectWith( BinSearchTree *bst );
  BinSearchTree *unionWith( BinSearchTree *bst );
  BinSearchTree *differenceOf( BinSearchTree *bst );
  TreeNode * smallest(TreeNode * root);
  TreeNode *smallest();
  ~BinSearchTree();
  void removeSubtree(TreeNode* root);
private:
  int kthSmallest( int k , TreeNode * root);
  TreeNode *local_insert( TreeNode *, int );
  TreeNode *root;
  bool find(TreeNode * root , int v);
  void inorderDump(TreeNode * root);
  int maxDepth(TreeNode * root);
  int size(TreeNode * root);
  void levelOrderDump(TreeNode * root);
  TreeNode *remove(int v, TreeNode * root);
  void valuesAtLevel( int k , TreeNode* root, int n);
  int iterMaxDepth(TreeNode * root);
  bool hasRootToLeafSum( int sum , TreeNode* root );
  bool areIdentical(TreeNode * root ,TreeNode *bst  );
  BinSearchTree *intersectWith( TreeNode* root, TreeNode *bst ,BinSearchTree * common);		   
  BinSearchTree *unionWith( TreeNode* root, BinSearchTree *bst );
  BinSearchTree *differenceOf( TreeNode* root, TreeNode *bst ,BinSearchTree* common);
void iterValuesAtLevel( int k , TreeNode* root);  
  

};
