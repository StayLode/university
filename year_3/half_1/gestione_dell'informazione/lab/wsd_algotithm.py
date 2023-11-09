from nltk.corpus import wordnet as wn

def disambiguate(terms):
    for term_i in terms:
        selSense = None
        selScore = 0.0
        for sense_term_i in wn.synsets(term_i, wn.NOUN):
            conf_sense=0.0
            for term_j in terms:
                if(term_i!=term_j):
                    best_sense=0.0
                    for sense_term_j in wn.synsets(term_j, wn.NOUN):
                        temp_sense=sense_term_i.wup_similarity(sense_term_j)
                        if (temp_sense>best_sense):
                            best_sense=temp_sense
                    conf_sense = conf_sense + best_sense
            if (conf_sense>selScore):
                selScore = conf_sense
                selSense = sense_term_i
        if(selSense is not None):
            print(term_i,": ",selSense,", ",selSense.definition())
            print("Score: ", selScore)
        else:
            print(term_i,": --")

print("\nCat, Mouse, Dog: ")
disambiguate(["cat","mouse", "dog"])

print("\nComputer, Mouse, Laptop: ")
disambiguate(["computer","mouse", "laptop"])