class DisjointSetUnion:

    def __init__(self, n):
        self.size = [1 for i in range(n)]
        self.parent = [i for i in range(n)]

    def FindSet(self, x):
        if x == self.parent[x]:
            print(x)
            return x
        self.parent[x] = self.FindSet(self.parent[x])
        return self.parent[x]

    def Union(self, x, y):
        x = self.FindSet(x)
        y = self.FindSet(y)
        if x != y:
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]
            
    def Print(self):
        for item in self.parent:
            print(item, sep=" ", end=" ")
        print()
        for item in self.size:
            print(item, sep=" ", end=" ")
        print(end='\n\n')
        
            
    
if __name__ == "__main__":
    temp = DisjointSetUnion(6)
    temp.Print()
    temp.Union(1, 2)
    # temp.Print()
    temp.Union(3, 4)
    # temp.Print()
    temp.Union(1, 3)
    # temp.Print()
    temp.Union(3, 5)
    # temp.Print()
    temp.Union(1, 5)
    # temp.Print()