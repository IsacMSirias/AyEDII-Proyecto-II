/* C++ program to implement basic stack
   operations */
#include <bits/stdc++.h>
#include "rgbMatrix.h"
#include "rgbMatrix.cpp"
#include <vector>

using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;
 
public:
    vector<rgbMatrix> a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(rgbMatrix x);
    rgbMatrix pop();
    rgbMatrix peek();
    bool isEmpty();
};
 
bool Stack::push(rgbMatrix x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a->push_back(x);
        //cout << x.get_Width() << " pushed into stack\n";
        return true;
    }
}
 
rgbMatrix Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return rgbMatrix(0, 0);
    }
    else {
        rgbMatrix x = a[top--];
        return x;
    }
}
rgbMatrix Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return rgbMatrix(0, 0);
    }
    else {
        rgbMatrix x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(rgbMatrix(123, 432));
    s.push(rgbMatrix(123, 432));
    s.push(rgbMatrix(123, 432));
    cout << s.pop().get_Width() << " Popped from stack\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek().get_Width() <<" ";
        // remove top element in stack
        s.pop();
    }
 
    return 0;
}