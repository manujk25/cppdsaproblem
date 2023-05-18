#include<queue>
class compare{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data>b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    Node<int>* ans= new Node<int>(-1);
    Node<int>* temp=ans;
    priority_queue<Node<int>*, vector<Node<int>*>, compare> pq;

    for(int i=0; i<listArray.size(); i++){
        if(listArray[i]!=NULL) 
            pq.push(listArray[i]);
    }
    
    while(pq.size()){
        Node<int>* top = pq.top();
        temp->next=top;
        pq.pop();
        temp=temp->next;

        if(top->next){
            pq.push(top->next);
        }
    }

    return ans->next;
}
