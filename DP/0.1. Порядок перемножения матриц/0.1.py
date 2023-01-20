with open('input.txt', encoding='utf-8') as file:
    N = int(file.readline())
    array_0 = list()
    [array_0.append(int(file.readline().split()[0])) for i in range(0, N - 1)]
    [array_0.append(int(i)) for i in file.readline().split()]
    
def matrix_order(array_0):
    list_0 = [[0 for _ in range(len(array_0))] for _ in range(len(array_0))]
    for l in range(2, len(array_0)):
        for i in range(1, len(array_0) - l + 1):
            j = i + l - 1
            list_0[i][j] = float('Inf')
            for k in range(i, j):
                list_0[i][j] = min(list_0[i][j], list_0[i][k] + list_0[k + 1][j] + array_0[i - 1] * array_0[k] * array_0[j])  
    return list_0[1][len(array_0) - 1]

with open('output.txt', 'w') as file_1:
    file_1.write(str(matrix_order(array_0)))