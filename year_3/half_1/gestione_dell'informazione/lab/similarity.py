from nltk.corpus import wordnet as wn

dog = wn.synset("dog.n.01")
cat = wn.synset("cat.n.01")
computer = wn.synset("computer.n.01")

#DISTANCE-BASED SIMILARITY
#   Path-Distance similarity
print("Path-Distance similarity:")
print("dog --> cat: "+str(dog.path_similarity(cat)))
print("dog --> computer: "+str(dog.path_similarity(computer)))

#Si nota come la differenza sia relativamente bassa nonostante la differenza di significato

#   Wu-Palmer similarity
print("\nWu-Palmer similarity:")
print("dog --> cat: "+str(dog.wup_similarity(cat)))
print("dog --> computer: "+str(dog.wup_similarity(computer)))

#CONTENT-BASED SIMILARITY
#   Resnik similarity
from nltk.corpus import wordnet_ic
brown_ic = wordnet_ic.ic("ic-brown.dat") #Permette di calcolare P(c)

print("\nResnik similarity:")
print("dog --> cat: "+str(dog.res_similarity(cat,brown_ic))) #Calcola la Resnik, ovvero il logaritmo di P(c)
print("dog --> computer: "+str(dog.res_similarity(computer,brown_ic)))
