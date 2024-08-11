

/*
# 155. Min Stack
*/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
      this->val=val;
      this->next=next;
    }
};
class MinStack {
public:
    Node* head;
    int size;
    MinStack() {
       this->head=NULL;
       this->size=0;
        
    }
    
    void push(int val) {
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    
    void pop() {
        if(head==NULL){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        head=head->next;
        size--;
    }
    
    int top() {
        if(head==NULL){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return head->val;
    }
    
    int getMin() {
        Node* temp=head;
        int mn=INT_MAX;
        while(temp){
           mn=min(mn,temp->val);
           temp=temp->next;
        }
        return mn;
    }
};

int main(){
  MinStack m1;
  m1.push(10);
  m1.push(20);
  m1.push(30);
  m1.push(5);
  cout<<m1.top()<<endl;
  cout<<m1.getMin()<<endl;
  return 0;

}
