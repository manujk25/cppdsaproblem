#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void heapify(int arr[] , int size , int index)
{
  int largest = index;
  int leftindex = 2*index;
  int rightindex = 2*index +1 ;

  if(leftindex <= size && arr[largest] < arr[leftindex])
  {
    largest = leftindex ;
    
  }
  if(rightindex <= size && arr[rightindex] > arr[largest])
  {
    largest = rightindex;
  }

  if(largest!=index)
  {
    swap(arr[index] , arr[largest]);
    heapify(arr, size , largest);
  }
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
//Inorder traversal  of the tree
void inorder(Node* root){
    //base case
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//Preorder Traversal of the tree;
void preorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//for post order traversal of the tree
void postorder(Node* root){
    //base case
    if(root==NULL){
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}
Node* insertToBST(Node* root ,int d){
    //base case
    if(root==NULL){
        root = new Node(d);
        return root;
    } 
    if(d > root->data){
        //right part me insert Krna h 
        root->right = insertToBST(root->right,d);
    }
    else{
        //left part me insert krna h 
        root->left = insertToBST(root->left ,d);
    }
}
Node* minValue(Node* root){
    Node* temp =root;
    while(temp->left !=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right !=NULL){
        temp  = temp->right;
    }
    return temp;
}
Node* deleteNode(Node* root , int val){
    //base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        //0 child 
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left ==NULL && root->right !=NULL){
            Node* temp = root->left;
            temp=root->left;
            delete root;
            return temp;
        }
        if(root->left !=NULL && root->right == NULL){
            Node* temp = root->right;
            temp=root->right;
            delete root;
            return temp;

        }


        //2 child
        if(root->left !=NULL && root->right !=NULL){
            int mini =minValue(root->right) -> data;
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root; 
        }
    }
    else if(root->data >= val){
        //left part ke liye
        root->left = deleteNode(root->left , val);
        return root;
    }else{
        //right part wale ke liye
        root->right = deleteNode(root->right , val);
        return root;
    }
}
void takeInput(Node* &root){
   int data;
   cin>>data;

   while(data != -1){
    root = insertToBST(root,data);
    cin>>data;
   } 
}
void heapsort(int arr[] ,int n){
    int size =n;
    while(size>1){
         //step1: Swap
        swap(arr[size],arr[1]);
        size--;
        //step2
        heapify(arr,size,1);
    }
}
int main()
{
    Node* root =NULL;
    cout<<"Enter the Data to create the BST:-"<<endl;
    takeInput(root);
    cout<<"Print the Binary Search Tree"<<endl;
    levelOrderTraversal(root);

    //left root right
    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;

    //root left right
    cout<<"PreOrder Traversal:"<<endl;
    preorder(root);
    cout<<endl;
    
    //left right root
    cout<<"PostOrder Traversal:"<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Min Val is ="<<minValue(root) ->data<<endl;
    cout<<"Max Val is ="<<maxValue(root) ->data<<endl;


    //Deletion of the Node
    root = deleteNode(root , 30);

    cout<<"-------------------After the Deletion of the Node-----------------"<<endl;

    cout<<"Print the Binary Search Tree"<<endl;
    levelOrderTraversal(root);

    //left root right
    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;

    //root left right
    cout<<"PreOrder Traversal:"<<endl;
    preorder(root);
    cout<<endl;
    
    //left right root
    cout<<"PostOrder Traversal:"<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Min Val is ="<<minValue(root) ->data<<endl;
    cout<<"Max Val is ="<<maxValue(root) ->data<<endl;

    //for heapify the function we use the heapify algorithm
    int arr[6]={-1,54,58,52,50,56};
    int n=5;
    //heap creation
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    //printing after buliding the heap
    cout<<"printing the Array After Building the heap:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //function call for heap sort
    heapsort(arr,n);

    //Printing after Heap SOrting of the Function
    cout<<"printing the Array After Heap Sort"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
return 0;
}
