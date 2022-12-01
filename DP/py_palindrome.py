def findpal(Palindrom):
    print(Palindrom)
    size = len(Palindrom)
    OldStr = [[0 for _ in range(0, size)] for _ in range(0, size)]
    
    for i in range(0, size):
        OldStr[i][i] = 1
        
    for k in range(1, size):
        for i in range(0, size - k):
            j = i + k
            if Palindrom[i] == Palindrom[j]:
                OldStr[i][j] = OldStr[i + 1][j - 1] + 2
            elif Palindrom[i] != Palindrom[j]:
                OldStr[i][j] = max(OldStr[i + 1][j], OldStr[i][j - 1])  
                
    down = 0
    left = size - 1
    TPalindrome = list()
    
    while OldStr[down][left]:
        print(Palindrom[left], Palindrom[down])
        print(left, down)
        if Palindrom[left] == Palindrom[down]:
            TPalindrome.append(Palindrom[left])
            left -= 1
            down += 1
        elif Palindrom[left] != Palindrom[down]:
            if OldStr[left - 1][down] > OldStr[left][down - 1]:
                left -= 1
            elif OldStr[left - 1][down] <= OldStr[left][down - 1]:
                down += 1
                
    TPalindrome += TPalindrome[::-1]
    
    print(TPalindrome)
                    
    with open('output.txt', 'w') as file_0:
        file_0.write(str(len(TPalindrome)) + '\n')
        for s in TPalindrome:
            file_0.write(str(s))
        
if __name__ == '__main__':
    with open('input.txt', encoding='utf-8') as file:
        Palindrom = list(file.readline())
    findpal(Palindrom)
                