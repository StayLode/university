from urllib import request
import nltk

#Acquisizione testo

url = "http://www.gutenberg.org/files/2554/2554-0.txt"
response = request.urlopen(url)
raw = response.read().decode('utf8')

#Preprocessing

tokens = nltk.word_tokenize(raw)
print(tokens)


tagged=nltk.pos_tag(tokens)

#print(tagged)

from nltk.corpus import stopwords

tokens2=set()   #Non ha i duplicati

for t in tokens:
   if not t in stopwords.words('english'):
       tt = nltk.pos_tag([t])
       if tt[0][1][0:2] == 'NN':
           tokens2.add(t)

#print( "Tokens after elimination of stopwords and noun selection:")
#print( tokens2)

#Stemming
from nltk.stem.porter import PorterStemmer

porter = PorterStemmer()


for t in tokens2:
   print(porter.stem(t))