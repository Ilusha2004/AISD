# Problem 0.1. Построить дерево

*Input file name: input.txt\
Output file name: output.txt\
Time limit: 1 s\
Memory limit: 256 MB*

По набору ключей постройте бинарное поисковое дерево и выполните его прямой левый обход.

# Input

Входной файл содержит последовательность чисел — ключи вершин в порядке добавления в дерево. Ключи задаются в формате по одному в строке.
В поисковом дереве все ключи по определению уникальны, поэтому при попытке добавить в дерево ключ, который там уже есть, он игнорируется.

# Output

Выходной файл должен содержать последовательность ключей вершин, полученную прямым левым обходом дерева.

# Examples

| input.txt                                      |output.txt                                      |
|------------------------------------------------|------------------------------------------------|
| 2 3                                            | 2 3                                            |
| 5 2 4 1 8 7                                    | 5 2 1 4 8 7                                    |
| 0 100 -100                                     | 0 -100 100                                     |