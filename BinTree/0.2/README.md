# Problem 0.2. Удалить из дерева

*Input file name: input.txt\
Output file name: output.txt\
Time limit: 1 s\
Memory limit: 256 MB*

По набору ключей постройте бинарное поисковое дерево. Удалите из него ключ (правым удалением), если он есть в дереве. Выполните прямой левый обход полученного дерева.

# Input

В первой строке записано целое число — ключ, который нужно удалить из дерева.
Вторая строка пустая.

Последующие строки содержат последовательность чисел — ключи вершин в порядке добавления в дерево. Ключи задаются в формате по одному в строке. Дерево содержит хотя бы две вершины.

Напомним, что в поисковом дереве все ключи по определению уникальны, поэтому при попытке добавить в дерево ключ, который там уже есть, он игнорируется.

# Output

Выведите последовательность ключей вершин, полученную прямым левым обходом дерева.

# Examples

| input.txt                                      |output.txt                                      |
|------------------------------------------------|------------------------------------------------|
| 3  2 3 1                                       | 2 1                                            |
| 2  4 2 1 3 5                                   | 4 3 1 5                                        |