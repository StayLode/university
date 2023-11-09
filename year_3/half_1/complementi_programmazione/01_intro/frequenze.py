testo = input('immetti un testo lungo: ')
frequenze={}
for c in testo:
    frequenze[c] = frequenze.get(c, 0) + 1

l = sorted(frequenze.items(), key=lambda x:x[1]) #con .items() otteniamo una lista di tuple (carattere, frequenza)
print(l)