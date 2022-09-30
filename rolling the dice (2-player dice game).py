import random

def roll():
    return random.choice([1,2,3,4,5,6])

class player(object):
    def __init__(self, name, age, colour):
        self.name = name
        self.age = age
        self.colour = colour
        
    def score(self, score):
        self.score = score    
    def getscore(self):
        return self.score
    
    def getname(self):
        return self.name
    def __str__(self):
        return 'NAME: ' + self.name + '\nCOLOUR: ' + self.colour + '\nSCORE: ' + str(self.score)
    

class game(object):
    def __init__(self, playr, trails):
        self.trails = trails
        self.playr = playr
        
    def gaming(self):
        throw = 0
        score = 0
        for i in range(self.trails):
            throw = roll()
            if throw == 6:
                throw = throw + roll()
            score = throw + score    
        return score
        
    def __str__(self):
        return self.playr.getname() + str(self.score)
tri = 123        
    


zack = player('zack', 24, 'green')
johny = player('johny', 25, 'yellow')
kina = player('kina', 14, 'red')
usher = player('usher', 13, 'blue')
print("-----------LETs PLAy THIs GAMe--------------\n" )
#zack.score(88)
#print(zack)
zackscr = game(zack, tri)
johnyscr = game(johny, tri)
kinascr = game(kina, tri)
usherscr = game(usher, tri)

scr = []
scr.append(zackscr.gaming())
scr.append(johnyscr.gaming())
scr.append(kinascr.gaming())
scr.append(usherscr.gaming())

scrsort = sorted(scr)
for el in scrsort:
    print(el)


zack.score(scr[0])
usher.score(scr[3])
kina.score(scr[2])
johny.score(scr[1])

#players = []
#players.append(zack.getscore())
#players.append(usher.getscore())
#players.append(kina.getscore())
#players.append(johny.getscore())
# =============================================================================
# =============================================================================
# =============================================================================
# # # = = = = = = == = = = == = = == = = = == = = == = = == = = == == = == == =

#for el in players:
#    print('--', el)
#print(scr[0])        
print(zack, '\n')
print(kina, '\n')
print(johny, '\n')
print(usher, '\n')
