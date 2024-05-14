/*

Balanced Parentheses

Given a string with the just the six characters - ‘(’, ‘)’, ‘{’, ‘}’, ‘[’ and ‘]’. Determine if the string is balanced.

A string is balanced if all brackets exist in pairs and are closed in the correct order.

*/

bool isBalancedParentheses(string str) {
    std::stack<char> s;
	
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		} else {
			if (s.empty()) {
				return false;
			}

			char ch = s.top();
			s.pop();
			
			if (
				!((ch == '{' && str[i] == '}') || 
				(ch == '[' && str[i] == ']') || 
				(ch == '(' && str[i] == ')'))
			) {
				return false;
			}
		}
	}
	
	if (!s.empty()) {
		return false;
	}
	
	return true;
}