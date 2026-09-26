class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        stack<int> stk;
        int ans =0;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                auto num1 = stk.top();stk.pop();
                auto num2 = stk.top();stk.pop();
                
                ans = num1+num2;
                stk.push(num1+num2);
            }
            else if(tokens[i]=="*")
            {

                auto num1 = stk.top();stk.pop();
                auto num2 = stk.top();stk.pop();
                ans = num1*num2;
                stk.push(num1*num2);
                
            }
            else if(tokens[i]=="-")
            {

                auto num1 = stk.top();stk.pop();
                auto num2 = stk.top();stk.pop();
                ans = num2-num1;
                stk.push(num2-num1);
            
            }
            else if(tokens[i]=="/")
            {

                auto num1 = stk.top();stk.pop();
                auto num2 = stk.top();stk.pop();
                
                ans = (num2/num1);
                stk.push(num2/num1);
            
            }
            else
                stk.push(stoi(tokens[i]));

            // cout << ans << endl;
        }
        return ans;
    }
};
