class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, current = 0;
        stack<int> st;
        
        while(current < height.size()){
            while(!st.empty() && height[current] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                res += distance * bounded_height;
                
                //cout << "current is: " << current << "st.top() is: " << st.top() << endl;
            } 
            st.push(current++);
        }
        return res;
    }
};
