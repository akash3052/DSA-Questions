void insertSorted(stack<int> &s, int element){
    if(s.empty() || element>s.top()){
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    insertSorted(s,element);
    s.push(top);
}

void sortStack(stack<int> &s){
    // one element will always be sorted.
    if(s.size() == 1){
        return;
    }
    // Here, couldn't find any decision taking thing. So, making the input smaller and calling recursive function on smaller input.
    int top = s.top();
    s.pop();
    // Below step is called Hypothesis.(Assuming, if the function worked for input of size n , then it will also work on input of size 'n-1')
    sortStack(s);
    // Now, we are inserteing the element we popped in the sorted stack with size reduced by 1.
    // This step is called Induction.
    insertSorted(s,top);
}

void SortedStack :: sort()
{
   //Your code here
   sortStack(s);
}
