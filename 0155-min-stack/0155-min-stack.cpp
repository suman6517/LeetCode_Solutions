// class MinStack {
// public:
//     long long min = INT_MAX;
//     stack<int>st;
//     MinStack() 
//     {
        
//     }
    
//     void push(int val) 
//     {
//         if(st.empty())
//         {
//             min = val;
//             st.push(val);
//         }
//         else if(val >min)
//         {
//             st.push(val);
//         }
//         else
//         {
            
//             st.push(2*val - min);
//             min = val;
//         }
        
//     }
    
//     void pop() 
//     {
//         if(st.empty())
//         {
//             return;
//         }
//         int x = st.top();
//         if (x < min) 
//         {
//         min = 2 * min - x;
//         }

//         st.pop();
//     }
    
//     int top() 
//     {
//         if(st.empty())
//         {
//             return 0;
//         }

//         int x = st.top();
//         if(x>min)
//         {
//             return x;
//         }
//         else
//         {
//             return min;
//         }
        
//     }
    
//     int getMin() 
//     {
//         return min;
        
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */
class MinStack {
public:
    long long min;
    stack<long long> st;

    MinStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            min = val;
            st.push(val);
        } else if (val >= min) {
            st.push(val);
        } else {
            st.push(2LL * val - min);
            min = val;
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        long long x = st.top();
        if (x < min) {
            min = 2LL * min - x;
        }
        st.pop();
    }

    int top() {
        if (st.empty()) {
            return 0;
        }
        long long x = st.top();
        if (x < min) {
            return min;
        } else {
            return x;
        }
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
