class Solution {
public:
    int operations(int a , int b, string op){
        if(op == "+") return a + b;
        if(op == "*") return (long)a * (long)b;
        if(op == "/") return a / b;
        if(op == "-") return a - b;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = operations(a , b, tokens[i]);

                st.push(result);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

// using LAMBDA function + stack 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };

        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
