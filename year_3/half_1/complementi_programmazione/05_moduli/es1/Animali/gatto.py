
class Gatto:
    
    def __init__(self, sesso, eta=0):
        self.sesso=sesso
        self.eta=eta


    @staticmethod
    def miagola():
        print("Miaoo")
    
    
def stessoLuogo(gatto1, gatto2):
    return gatto1.eta==gatto2.eta