
class Cane:
    cont=0
    
    def __new__(cls, *args, **kwargs):
        cls.cont+=1
        return object.__new__(cls)
    
    def __init__(self, sesso, eta=0):
        self.sesso=sesso
        self.eta=eta
        #Cane.cont+=1
    
    @classmethod
    def instances(cls):
        print(cls.cont)

    @staticmethod
    def abbaia():
        print("Sono il fazzone")
    
def stessoLuogo(cane1, cane2):
    return cane1.eta==cane2.eta