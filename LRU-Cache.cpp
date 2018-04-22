#include<bits/stdc++.h>

using namespace std;

struct QNode{
    QNode *prev,*next;
    int pageNumber;
};

struct Queue{
    int capacity,count;
    QNode *front,*rear;
}Q;

QNode *hashTable[10];

void initialise(int n){
    Q.capacity=n;
    Q.count=0;
    Q.front=Q.rear=NULL;
    for(int i=0;i<10;i++){
        hashTable[i]=NULL;
    }
}

QNode* newnode(int n){
    QNode *p = new QNode;
    p->pageNumber = n;
    p->prev=p->next=NULL;
    return p;
}

void deleteNode(QNode *ptr){
    if(ptr==Q.rear) Q.rear = ptr->prev;
    if(ptr->prev) ptr->prev->next = ptr->next;
    if(ptr->next) ptr->next->prev = ptr->prev;
    delete ptr;
    hashTable[ptr->pageNumber] = NULL;
    Q.count--;
}

void insert(int n){
    QNode *p = newnode(n);
    if(Q.capacity==Q.count)
        deleteNode(Q.rear);

    p->next = Q.front;
    if(Q.front!=NULL)
        Q.front->prev=p;
    else Q.rear=p;
    Q.front = p;
    Q.count++;
    hashTable[n] = p;
}

void refPage(int n){
    if(hashTable[n]==NULL){
        insert(n);
        return;
    }
    if(hashTable[n]==Q.front) return;

    QNode *ptr = hashTable[n];
    deleteNode(ptr);
    insert(n);
}

void print(){
    QNode *p=Q.front;
    while(p) {
        cout<<p->pageNumber << " ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    initialise(3);
    refPage(1);
    refPage(2);
    refPage(3);
    refPage(2);
    refPage(4);
    refPage(1);
    print();
}
