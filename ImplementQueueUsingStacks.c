typedef struct {
    int top;
    int arr[100];
} MyQueue;
MyQueue q;

MyQueue* myQueueCreate() {
    q.top=-1;
    return &q;    
}

void myQueuePush(MyQueue* obj, int x) {
    obj->top+=1;
    obj->arr[obj->top]=x;
}

int myQueuePop(MyQueue* obj) {
    int poppedValue=obj->arr[0];
    for(int i=1;i<=obj->top;i++){
        obj->arr[i-1]=obj->arr[i];
    }
    obj->top-=1;
    return poppedValue;
}

int myQueuePeek(MyQueue* obj) {
    int peekValue=obj->arr[0];
    return peekValue;
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->top==-1){
        return true;
    }
    else{
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    obj->top=-1;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
