def is_balanced(expression):
    stack = []
    pairs = {')': '(', ']': '[', '}': '{'}

    for char in expression:
        if char in '([{':
            stack.append(char)
        elif char in ')]}':
            if not stack or stack.pop() != pairs[char]:
                return False
    return not stack

expr = input("Enter an expression: ")
if is_balanced(expr):
    print("Balanced")
else:
    print("Not Balanced")
