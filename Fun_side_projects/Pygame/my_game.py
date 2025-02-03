import pygame
from sys import exit
pygame.init()
screen = pygame.display.set_mode((800,400))
pygame.display.set_caption("my_game")
clock = pygame.time.Clock()
font = pygame.font.Font("font/Pixeltype.ttf",50)
Sky_surface = pygame.image.load("graphics/Sky.png")
ground_surface = pygame.image.load("graphics/ground.png")
text_surface = font.render("My game",False,'black')
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
    screen.blit(ground_surface,(0,300))
    screen.blit(Sky_surface,(0,0))
    screen.blit(text_surface,(300,50))
    
    pygame.display.update()
    clock.tick(60)