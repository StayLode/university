rubrica=[]

while True:
    operazione=input("Cosa vuoi fare: ")
    if operazione == 'stampa':
        for n, t in rubrica:
            print(f'nome: {n}, tel: {t}')

    elif operazione == 'ins':
        nome = input("Inserisci Nome: ")
        tel = input("Inserisci Telefono: ")
        rubrica.append((nome,tel))
        
    elif operazione == 'canc':
        to_del = input('Chi vuoi eliminare: ')
        for n, t in rubrica:
            if to_del == n:
                to_del = (n,t)
                break

        rubrica.remove(to_del)

        