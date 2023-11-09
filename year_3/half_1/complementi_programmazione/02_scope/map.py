def fun(x):
    return x**2

def decoratore(fun):
    def funplus(*args, **kwargs):
        new_arg = input("inserire un nuovo argomento: ")
        
        res= fun(*args, **kwargs) if len(new_arg)==0 else fun(new_arg)
        print(f"risultato: {res}")
        return res
    return funplus

@decoratore
def square(x):
    return int(x)**2
if __name__ == '__main__':
    
    var=input()

    l=[]
    while(var!='#'):
        try:
            l.append(int(var))
        except ValueError:
            print("Inserire solo degli interi")
        var=input()
    print(list(map(fun, l)))

    value=square(2)
