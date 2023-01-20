with open('input.txt', encoding='utf-8') as file:
    list = file.readline().split(" ")
    k, n = list[0], list[1]
    
List = [0 for _ in range(int(n))]
res = int(k)
if int(n) == 1:
    res = int(k)
elif int(n) == 2:
    res += + int(k) * int(k)
else:
    List[0] = int(k)
    List[1] = int(k) * int(k)
    res += int(k) * int(k)
    for i in range(2, int(n)):
        List[i] = List[i - 2] * int(k) + List[i - 1] * int(k)
        res += List[i]
        
with open('output.txt', 'w') as file_0:
    file_0.write(str(res))