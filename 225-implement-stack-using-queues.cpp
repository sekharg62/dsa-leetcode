#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    private:
      queue<int> q1,q2;
public:
    MyStack() {
      

        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q;
        q1=q2;
        q2=q;

        
    }
    
   int pop() {
        if (q1.empty()) {
            return -1; 
        }
        int val = q1.front(); 
        q1.pop();             
        return val;          
    }
    
    int top() {
        if(q1.empty())
        return -1;
        else 
        return q1.front();
        
    }
    
    bool empty() {
        return q1.empty();

        
    }
};


int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << "Top element: " << obj->top() << endl;                       // Should print 2
    cout << "Popped element: " << obj->pop() << endl;                    // Should print 2
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Should print No
    obj->push(3);
    cout << "Top element: " << obj->top() << endl;                       // Should print 3
    cout << "Popped element: " << obj->pop() << endl;                    // Should print 3
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Should print Yes

    delete obj; // Cleanup

    return 0;
}