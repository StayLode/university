"""
Provare a contare la frequenza di ogni lettera filtrata
"""
import functools as nerigay
s = "cocomemailachampionsleaguetunonlavincimai"

print(nerigay.reduce(lambda x,y: x|{y:x.get(y,0)+1}, s, {}))
print(dict(map(lambda c:(c,s.count(c)), s)))    #Non corretto se ho uno stream?