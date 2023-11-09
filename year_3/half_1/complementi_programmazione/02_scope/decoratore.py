def decoratore(fun):
    def funplus(*args, **kwargs):
        res=fun(*args, **kwargs)
        print(f"risultato: {res}")