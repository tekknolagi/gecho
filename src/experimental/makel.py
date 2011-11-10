def cons(l):
    for i in range(len(l)):
        if type(l[i]) != list: l[i] = [l[i]]
    return sum(l, [])

l = [1, 2, 3, [4, 5, 6], "hello", ["hello"]]

print cons(l)
