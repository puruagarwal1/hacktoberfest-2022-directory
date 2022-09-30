import pygame
import time
import random
 
pygame.init()
 
display_width = 1275
display_height = 655
 
black = (0,0,0)
white = (255,255,255)

red = (200,0,0)
green = (0,200,0)

bright_red = (255,0,0)
bright_green = (0,255,0)

background_color = (36, 210, 236)
block_color = (53,115,255)
 
car_width = 73
car_height = 82
 
gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Off The Web')
clock = pygame.time.Clock()
 
carImg = pygame.image.load('racecar.png')
#gameIcon = pygame.image.load('carIcon.png')

#pygame.display.set_icon(gameIcon)

pause = False
#crash = True

def things_dodged(count):
    font = pygame.font.SysFont("comicsansms", 25)
    text = font.render("Dodged: "+str(count), True, black)
    gameDisplay.blit(text,(0,0))
 
def things(thingx, thingy, thingw, thingh, color):
    pygame.draw.rect(gameDisplay, color, [thingx, thingy, thingw, thingh])
 
def car(x,y):
    gameDisplay.blit(carImg,(x,y))
 
def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()
 
 
def crash():
    pygame.mixer.music.stop()
    largeText = pygame.font.SysFont("comicsansms",115)
    TextSurf, TextRect = text_objects("You Crashed", largeText)
    TextRect.center = ((display_width/2),(display_height/2))
    gameDisplay.blit(TextSurf, TextRect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                
        

        button("Play Again",320,450,100,50,green,bright_green,game_loop)
        button("Quit",840,450,100,50,red,bright_red,quitgame)

        pygame.display.update()
        clock.tick(15) 

def button(msg,x,y,w,h,ic,ac,action=None):
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()

    if x+w > mouse[0] > x and y+h > mouse[1] > y:
        pygame.draw.rect(gameDisplay, ac,(x,y,w,h))
        if click[0] == 1 and action != None:
            action()         
    else:
        pygame.draw.rect(gameDisplay, ic,(x,y,w,h))
    smallText = pygame.font.SysFont("comicsansms",20)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ( (x+(w/2)), (y+(h/2)) )
    gameDisplay.blit(textSurf, textRect)
    

def quitgame():
    pygame.quit()
    quit()

def unpause():
    global pause
    pygame.mixer.music.unpause()
    pause = False
    

def paused():
    pygame.mixer.music.pause()
    largeText = pygame.font.SysFont("comicsansms",115)
    TextSurf, TextRect = text_objects("Paused", largeText)
    TextRect.center = ((display_width/2),(display_height/2))
    gameDisplay.blit(TextSurf, TextRect)
    

    while pause:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()


        button("Continue",320,450,100,50,green,bright_green,unpause)
        button("Quit",840,450,100,50,red,bright_red,quitgame)

        pygame.display.update()
        clock.tick(15)   


def game_intro():

    intro = True

    while intro:
        for event in pygame.event.get():
            #print(event)
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                
        gameDisplay.fill(white)
        largeText = pygame.font.SysFont("comicsansms",115)
        TextSurf, TextRect = text_objects("Off The Web", largeText)
        TextRect.center = ((display_width/2),(display_height/2))
        gameDisplay.blit(TextSurf, TextRect)

        button("GO!",320,450,100,50,green,bright_green,game_loop)
        button("Quit",840,450,100,50,red,bright_red,quitgame)

        pygame.display.update()
        clock.tick(15)
        
        
    
    

    
def game_loop():
    global pause
    pygame.mixer.music.load('piano.mp3')
    pygame.mixer.music.play(-1)
    x = (display_width * 0.45)
    y = (display_height * 0.8)
 
    x_change = 0
     
    thing_startx = random.randrange(0, display_width)
    thing_starty = -600
    thing_speed = 4
    thing_width = 100
    thing_height = 100
 
    thingCount = 1

    dodged = 0
    
    gameExit = False
 
    while not gameExit:
 
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
 
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -10
                if event.key == pygame.K_RIGHT:
                    x_change = 10
                if event.key == pygame.K_p:
                    pause = True
                    paused()
                    
 
            if event.type == pygame.KEYUP:                  
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    x_change = 0
 
        x += x_change
        gameDisplay.fill(background_color)
 
        things(thing_startx, thing_starty, thing_width, thing_height, block_color)
       
        thing_starty += thing_speed
        car(x,y)
        things_dodged(dodged)
        
        if x > display_width - car_width or x < 0 :
            crash()

        if thing_starty > display_height:
            thing_starty = 0 - thing_height
            thing_startx = random.randrange(0,display_width)
            dodged += 1
            thing_speed += 1
            '''if dodged == 5:
                thing_speed += 0.5
                
            if dodged == 10:
                thing_speed += 0.8
                
            if dodged == 15:
                thing_width += (dodged * 0.3)
                thing_speed += 1.1
                
            if dodged == 20:
                thing_width += (dodged * 0.3)
                thing_speed += 1.4
                
            if dodged == 25:
                thing_width += (dodged * 0.3)
                thing_speed += 1.7
                
            if dodged == 30:
                thing_width += (dodged * 0.3)
                thing_speed += 2.0
                
            if dodged == 35:
                thing_width += (dodged * 0.3)
                thing_speed += 2.3
            if dodged == 40:
                thing_width += (dodged * 0.3)
                thing_speed += 2.6
                
            if dodged == 45:
                thing_width += (dodged * 0.3)
                thing_speed += 2.9
                
            if dodged == 50:
                thing_width += (dodged * 0.3)
                thing_speed += 3.2
                
            if dodged == 55:
                thing_width += (dodged * 0.3)
                thing_speed += 3.5
                
            if dodged == 60:
                thing_width += (dodged * 0.3)
                thing_speed += 3.8
                
            if dodged == 65:
                thing_width += (dodged * 0.3)
                thing_speed += 4.1
                
            if dodged == 70:
                thing_width += 10000
                thing_speed = 5
                print(" SUPRISE !!! ")'''
                
        if y < thing_starty+thing_height:
            #print('y crossover')
 
            if x > thing_startx and x < thing_startx + thing_width or x+car_width > thing_startx and x + car_width < thing_startx+thing_width:
                #print('x crossover')
                crash()
        
        pygame.display.update()
        clock.tick(60)

game_intro()
game_loop()
pygame.quit()
quit()
