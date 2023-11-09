from whoosh.index import create_in, open_dir
from whoosh.fields import *
import os, os.path

#*Crea l'indice nella directory "indexdir" e aggiunge due documenti all'indice, il cui contenuto non è però leggibile

schema = Schema(title=TEXT(stored=True), path=ID(stored=True), content=TEXT) #* Con stored=true facciamo si che venga salvato il pezzo di testo originale
if not os.path.exists("indexdir"):
    os.mkdir("indexdir")

ix = create_in("indexdir", schema)      #*Creazione dell'indice, gli passo la directory in cui salvare l'index e lo schema, analizzatore sintattico è quello di default simile a StandardAnalyzer

writer = ix.writer()

#* Aggiungiamo i documenti
writer.add_document(title=u"First document", path=u"/a", content=u"This is the first document we've added!")
writer.add_document(title=u"Second document", path=u"/b", content=u"The second one is even more interesting!")

#* Rendiamo definitiva l'operazione di scrittura:
writer.commit()