from whoosh.index import open_dir
from whoosh.qparser import QueryParser


ix = open_dir("indexdir")

searcher = ix.searcher()

parser = QueryParser("content", ix.schema)
query =parser.parse(u"document")

results = searcher.search(query)

if len(results) == 0:
    print("Nothing Found!")
else:
    for x in results:
        print(x)
print()