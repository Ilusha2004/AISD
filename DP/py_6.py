with open('input.txt', encoding='utf-8') as file:
    N = int(file.readline())
    arr = list(file.readline().split())
    
def UpperBount(arr, x):
    arr.sort()
    left = 0
    right = len(arr)
    middle = 0
    while left < right:
        middle = (right + left) // 2
        if arr[middle] > str(x):
            right = middle
        elif arr[middle] <= str(x):
            left = middle + 1
    return left

def MaxUpper(arr):
    list_0 = list()
    list_0.append(arr[0])
    for i in range(1, len(arr)):
        if int(arr[i - 1]) < int(arr[i]):
            list_0.append(arr[i])
        elif int(arr[i - 1]) >= int(arr[i]):
            list_0[UpperBount(list_0, arr[i])] = arr[i]
            
    return list_0

with open('output.txt', 'w') as file_0:
    file_0.write(str(len(MaxUpper(arr))))

            