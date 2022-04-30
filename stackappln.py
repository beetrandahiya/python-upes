a=""

# infix to postfix conversion
def infix_to_postfix(infix):
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    op_stack = []
    postfix_list = []
    token_list = infix.split()
    for token in token_list:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfix_list.append(token)
        elif token == '(':
            op_stack.append(token)
        elif token == ')':
            top_token = op_stack.pop()
            while top_token != '(':
                postfix_list.append(top_token)
                top_token = op_stack.pop()
        else:
            while (len(op_stack) > 0) and (prec[op_stack[-1]] >= prec[token]):
                  postfix_list.append(op_stack.pop())
            op_stack.append(token)
    while len(op_stack) > 0:
        postfix_list.append(op_stack.pop())
    return " ".join(postfix_list)

a=infix_to_postfix("(-b+((b*b)-4*a*c)^(0.5)/(2*a))")
print(a)