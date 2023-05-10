#include <iostream>
using namespace std;
class heap{
   public:
   int arr[100];
   int size = 0;

   heap(){
    arr[0]=-1;
    size=0;
   }

   void insert(int val){
    size = size+1;
    int index =size;
    arr[index]=val;

    while(index>1){
       int parent  = index/2;

        if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }
        else{
            return ;
        }
    }
   } 
   void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }

   //DELETION OD THE nODE FROM THE HEAP
 void deleteRoot(){
    if(size==0){
      cout << "Heap is empty\n";
      return;
    }
    //1st step
    arr[1]=arr[size];
    //2nd step
    size--;
    //3rd step
    int i=1;
    while(i<size){
      int leftInd=2*i;
      int rightInd=2*i+1;
     /* Modification - 1 */
      if(leftInd<=size && arr[i]<arr[leftInd] && arr[leftInd]>arr[rightInd]){
        swap(arr[i], arr[leftInd]);
        i=leftInd;
      }
      /* Modification - 2 */
      else if(rightInd<=size && arr[i]<arr[rightInd] && arr[rightInd]>arr[leftInd]){
        swap(arr[i], arr[rightInd]);
        i=rightInd;
      }else{
        return;
      }
    }
 }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout<<"The Insertion of the Heap then heaps look like:"<<endl;
    h.print();

    //delete the node from the Heap

    h.deleteRoot();
    cout<<"After Deltion of the root node from the Heap then the heap will be:"<<endl;
    h.print();
return 0;
}