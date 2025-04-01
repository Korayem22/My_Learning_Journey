import pygame
from sys import exit

def display_score():
    current_time = pygame.time.get_ticks() - start_time
    current_time //= 1000
    score_surface = font.render(f'Score: {current_time}',False,(64,64,64))
    score_rect = score_surface.get_rect(center=(400,50))
    screen.blit(score_surface,score_rect)
def game_over(score):
    screen.fill((94,129,162))
    screen.blit(player_stand,player_stand_rect)
    title_surface = font.render("Game Over",False,(111,196,169))
    screen.blit(title_surface,(400,50))
    score_surface = font.render(f'Your score: {score}',False,(111,196,169))
    score_rect = score_surface.get_rect(center=(400,330))
    screen.blit(score_surface,score_rect)
    restart_surface = font.render("Press space to restart",False,(111,196,169))
    restart_rect = restart_surface.get_rect(center=(400,370))
    screen.blit(restart_surface,restart_rect)
pygame.init()
screen = pygame.display.set_mode((800,400))
pygame.display.set_caption("PyRunner")
clock = pygame.time.Clock()
#game variables
start_time = 0
game_active = False
score = 0
player_gravity = 0
# import images
font = pygame.font.Font("font/Pixeltype.ttf",50)
Sky_surface = pygame.image.load("graphics/Sky.png").convert()
ground_surface = pygame.image.load("graphics/ground.png").convert()
##### 
player_stand = pygame.image.load("graphics/Player/player_stand.png").convert_alpha()
player_stand= pygame.transform.rotozoom(player_stand,0,2 )
player_stand_rect = player_stand.get_rect(center=(400,200))
player_surface = pygame.image.load("graphics/Player/player_walk_1.png").convert_alpha()
player_rect = player_surface.get_rect(midbottom=(80,300))
player_gravity = 0 
#####
snail_surface = pygame.image.load("graphics/snail/snail1.png").convert_alpha()
snail_rect = snail_surface.get_rect(midbottom=(600,300))
#####
#score_surface = font.render("PyRunner",False,(64,64,64))
#score_rect = score_surface.get_rect(center=(400,50))
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if game_active:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and player_rect.bottom >= 300:
                    player_gravity = -20
            if event.type == pygame.MOUSEBUTTONDOWN and player_rect.bottom >= 300:
                if player_rect.collidepoint(event.pos):
                        player_gravity = -20
        else:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                snail_rect.left = 800
                start_time = pygame.time.get_ticks()
                game_active = True
    if game_active:
        #score
        #background
        screen.blit(ground_surface,(0,300))
        screen.blit(Sky_surface,(0,0))
        if snail_rect.right <= 0:snail_rect.left = 800
        snail_rect.x -= 5
        screen.blit(snail_surface,snail_rect)
        #player
        player_gravity += 1
        player_rect.y += player_gravity
        if player_rect.bottom >= 300:player_rect.bottom = 300
        screen.blit(player_surface,player_rect)
        #collision
        if player_rect.colliderect(snail_rect):
            game_active = False
        display_score()
    else:
        score = (pygame.time.get_ticks() - start_time) // 1000
        game_over(score)
    pygame.display.update()
    clock.tick(60)