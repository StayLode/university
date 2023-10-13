import nltk

#Primo 
text = "This is a test"
tokens = nltk.word_tokenize(text) #Restituisce una lista di stringhe tokenizzate
print(tokens)

#Secondo
from nltk.corpus import stopwords

wnl = nltk.WordNetLemmatizer() #WordNet è un vocabolario che verrà usato dal lemmatizer per ridurre le parole
for t in tokens:
    if not t in stopwords.words('english'): #Controllo che una parola non sia una stopword
        print(wnl.lemmatize(t)) #Lemmatizza parole usando wnl, restituisce la forma lemmatizzata o l'input originale se non è riducibile

#Terzo
from nltk.stem.porter import PorterStemmer
porter = PorterStemmer()    # un oggetto stemmer di porter
print([porter.stem(t) for t in tokens])

#Quarto
from nltk.stem.lancaster import LancasterStemmer
lancaster = LancasterStemmer() #un oggetto stemmer di lancaster
print([lancaster.stem(t) for t in tokens])