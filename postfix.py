def evaluate_postfix(expression):
    stack = []
    for char in expression.split():
        if char.isdigit():  
            stack.append(int(char))
        else:
            right = stack.pop()
            left = stack.pop()
            
            if char == '+':
                stack.append(left + right)
            elif char == '-':
                stack.append(left - right)
            elif char == '*':
                stack.append(left * right)
            elif char == '/':
                stack.append(left / right) 
            elif char == '^':
                stack.append(left ** right)
    return stack.pop()

expr = input("Enter postfix expression (space separated): ")
result = evaluate_postfix(expr)
print("Result:", result)
