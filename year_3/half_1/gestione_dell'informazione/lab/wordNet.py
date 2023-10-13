from nltk.corpus import wordnet as wn

print("1.")
print(wn.synsets("dog"))

print("\n\n2.")
print(wn.synsets("dog",wn.VERB))

print("\n\n3.")
dog = wn.synset("dog.n.01")
print(dog.definition())

print("\n\n4.")
print(dog.examples())

print("\n\n5.")
print(dog.hypernyms())

print("\n\n6.")
print(wn.morphy("denied",wn.VERB)) #Riporta la parola alla forma base

print("\n\n7.")
print(wn.morphy("abaci")) 