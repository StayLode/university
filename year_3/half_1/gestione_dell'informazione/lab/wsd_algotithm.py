from nltk.corpus import wordnet as wn

def disambiguate(terms):
    for term_i in terms:
        for sense_term_i in wn.synsets(term_i, wn.NOUN):
            conf_sense=0.0
            for term_j in terms:
                if(term_i!=term_j):
                    best_sense=0.0
                    for sense_term_j in wn.synsets(term_j, wn.NOUN):
                        temp_sense=sense_term_i.wup_similarity(sense_term_j)
                        if (temp_sense>best_sense):
                                best_sense=temp_sense



disambiguate(["cat","dog"])