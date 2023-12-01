import random
from abc import ABC, abstractmethod

def myproperty(fun):
    class D:
        def __get__(self, instance, owner):
            return fun(instance)

        def setter(self, settfun):
            self.setfun=settfun

        def __set__(self, instance, value):
            self.setfun(instance, value)
    return D()

class Malato:
    def __init__(self):
        self.malato = False

    def __get__(self, instance, owner):
        return instance._Animale__malato_ and not instance.spavaldo
    
    def _set__(self, instance, value):
        instance._Animale__malato_ = value

class Animale(ABC):
    malato = Malato()
    def __init__(self, sesso, eta=0, coda=True, zampe=4):
        self.sesso = sesso
        self.eta = eta
        self.zampe = zampe
        self.coda = coda
        self.__spavaldo_ = False

    @myproperty
    def prova(self):
        return "ciao"

    @prova.setter
    def setprova(self, value):
        print("OK!")

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

    @abstractmethod
    def fai_verso(self):
        pass


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
    
    def fai_verso(self):
        print("MIAO")

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

    
    def fai_verso(self):
        print("Sono il fazzone")

if __name__ == '__main__':
    cane=Cane("m")
    cagna=Cane('f')
    gatto=Gatto('m')
    gatta=Gatto('f')

    try:
        cucciolo = gatta+gatto
        print(cucciolo.sesso)
    except Exception as e:
        print(e)

    Cane.instances()
    cane.fai_verso()
    gatto.fai_verso()

    cane.malato=False
    cane.spavaldo=True
    print(cane.malato)

    print(cane.prova)
    cane.prova=10
        