def flatten(l):
    res=[]
    
    if not hasattr(l[0], '__iter__'):
        return l
    
    for elem in l:
        res.extend(flatten(elem))
    return res

print(flatten([1,2]))