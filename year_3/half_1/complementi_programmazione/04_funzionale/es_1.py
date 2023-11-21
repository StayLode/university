"""
Partendo da una stringa molto lunga di caratteri minuscoli scrivere una sequenza 
di espressioni che tengano solo le consonanti e le rende maiuscole
"""

s = "cocomemailachampionsleaguetunonlavincimai"

#print(list(map(lambda x:x.upper(), (filter(lambda x: x not in ['a','e','i','o','u','A','E','I','O','U'], s)))))
print(list(filter(lambda x: x not in ['A','E','I','O','U'], s.upper())))
