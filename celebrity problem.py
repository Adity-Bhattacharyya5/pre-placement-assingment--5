def find_celebrity(M, n):
    a, b = 0, n - 1
  
    while a < b:
        if M[a][b] == 1:
            a += 1  
        else:
            b -= 1  
    
    candidate = a
    for i in range(n):
        if i != candidate:

            if M[candidate][i] == 1 or M[i][candidate] == 0:
                return -1 
    
    return candidate

M = [
    [0, 1, 0],
    [0, 0, 0],
    [0, 1, 0]
]
n = 3

print(find_celebrity(M, n))
