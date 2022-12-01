with open('in.txt', encoding='utf-8') as file:
    D, I, R = [int(file.readline()) for _ in range(0, 3)]
    str_0, str_1 = [list(file.readline().strip('\n')) for _ in range(0, 2)]
list_0 = [[0 for _ in range(0, len(str_1) + 1)] for _ in range(0, len(str_0) + 1)]
for i in range(0, len(str_0) + 1):
    list_0[i][0] = i * D
for i in range(0, len(str_1) + 1):
    list_0[0][i] = i * I
for i in range(1, len(str_0) + 1):
    for k in range(1, len(str_1) + 1):
        if str_0[i - 1] == str_1[k - 1]:
            list_0[i][k] = list_0[i - 1][k - 1]
            continue
        list_0[i][k] = min(list_0[i - 1][k] + D, list_0[i][k - 1] + I, list_0[i - 1][k - 1] + R)
with open('out.txt', 'w') as file_0:
    file_0.write(str(list_0[len(str_0)][len(str_1)]))