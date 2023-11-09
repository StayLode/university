import random

class Animale:
    
    def __init__(self, sesso, eta=0, coda=True, zampe=4):
        self.sesso = sesso
        self.eta = eta
        self.zampe = zampe
        self.coda = coda
        self.__malato_ = False
        self.__spavaldo_ = False

    @staticmethod
    def cammina():
        print("camminooooo")
    
    @staticmethod
    def corri():
        print("corroooo")
    
    @property
    def malato(self):
        return self.__malato_ and not self.__spavaldo_
    @malato.setter
    def malato(self, malato):
        self.__malato_ = malato

    @property
    def spavaldo(self):
        return self.__spavaldo_
    @spavaldo.setter
    def spavaldo(self, spavaldo):
        self.__spavaldo_ = spavaldo

    def __add__(self, other):
        if(self.sesso==other.sesso and type(self)==type(other)):
            raise Exception("Impossibile")
        else:
            return type(self)(sesso=random.choice(("M","F")))

class Gatto(Animale):
    
    def __init__(self, sesso, eta=0, coda=True, zampe=4):
        super().__init__(sesso, eta, coda, zampe)

    @staticmethod
    def cammina():
        print("camminooooo")
    
    @staticmethod
    def corri():
        print("corroooo")

class Cane(Animale):
    cont=0
    
    def __new__(cls, *args, **kwargs):
        cls.cont+=1
        return object.__new__(cls)
    
    def __init__(self, sesso, eta=0, coda=True, zampe=4):
        super().__init__(sesso, eta, coda, zampe)
        #Cane.cont+=1
    
    @classmethod
    def instances(cls):
        print(cls.cont)

    @staticmethod
    def abbaia():
        print("Sono il fazzone")

if __name__ == '__main__':
    cane=Cane("m")
    cagna=Cane('f')
    gatto=Gatto('m')
    gatta=Gatto('f')

    cane.malato=True
    cane.spavaldo=False
    print(cane.malato)

    try:
        cucciolo = gatta+gatto
        print(cucciolo.sesso)
    except Exception as e:
        print(e)

    Cane.instances()
        