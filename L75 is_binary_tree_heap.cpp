    int countNodes(struct Node* tree)
  {
      if(tree == NULL)
      return 0;
      int ans  = 1 + countNodes(tree->left) + countNodes(tree->right);
      return ans;
  }
 // to check whether the tree is CBT(complete Binary Tree) or not 
bool isCBT(struct Node* tree,int i, int count)
  {
      if(tree == NULL){
          return true;
      }
      if(i >= count)
      return false;
 
      else{
           bool left = isCBT(tree->left, 2*i+1,count);
           bool  right = isCBT(tree->right, 2*i+2,count);
          return(left && right);
      }
  }
//to find maxorder using heap
bool isMaxorder(struct Node* tree)
  {
      if(tree->left == NULL && tree->right==NULL )
      {
          return true;
      }
      
       if(tree->right == NULL){
           return (tree->data > tree->left->data);
       }
       
       else
       {
        bool left = isMaxorder(tree->left);
        bool right = isMaxorder(tree->right);
       
       return (left && right &&
       (tree->data > tree->left->data && tree->data > tree-> right->data));
       }
  }
// heap function
bool isHeap(struct Node* tree) {
        
        int index = 0;
        int countNode  = countNodes(tree);
        if(isCBT(tree,index,countNode)  && isMaxorder(tree)){
            return true;
        }
        else{
            return false;
        }
}
