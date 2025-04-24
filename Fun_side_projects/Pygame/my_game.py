import pygame
from random import randint
from sys import exit

class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        player_walk1 = pygame.image.load("graphics/Player/player_walk_1.png").convert_alpha()
        player_walk2 = pygame.image.load("graphics/Player/player_walk_2.png").convert_alpha()
        self.player_walk = [player_walk1,player_walk2]
        self.player_index = 0
        self.player_jump = pygame.image.load("graphics/Player/jump.png").convert_alpha()
        self.image = self.player_walk[self.player_index]
        self.rect = self.image.get_rect(midbottom=(80,300))
        self.gravity = 0

    def apply_gravity(self):
        self.gravity += 1
        self.rect.y += self.gravity
        if self.rect.bottom >= 300: self.rect.bottom = 300
    def player_input(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_SPACE] and self.rect.bottom >= 300:
            self.gravity = -20
    
    def animation_state(self):
        if self.rect.bottom < 300:
            self.image = self.player_jump
        else:
            self.player_index += 0.1
            if self.player_index >= 1.5: self.player_index = 0
    def update(self):
        self.player_input()
        self.apply_gravity()
        self.animation_state()
            
    
def display_score():
    current_time = pygame.time.get_ticks() - start_time
    current_time //= 1000
    score_surface = font.render(f'Score: {current_time}',False,(64,64,64))
    score_rect = score_surface.get_rect(center=(400,50))
    screen.blit(score_surface,score_rect)
    return current_time

def obstacle_movement(obstacle_list):
    if obstacle_list:
        for obstacle_rect in obstacle_list:
            obstacle_rect.x -= 5
            if obstacle_rect.bottom == 300: screen.blit(snail_surface,obstacle_rect)
            else: screen.blit(fly_surface,obstacle_rect)
        obstacle_list = [obstacle for obstacle in obstacle_list if obstacle.x> -100]       
        return obstacle_list
    else:
        return []

def collision(player,obstacle_list):
    if obstacle_list:
        for obstacle_rect in obstacle_list:
            if player.colliderect(obstacle_rect):
                return False
    return True

def player_animation():
    # player walking animation if player is on the ground
    # player jump animation if player is in the air
    global player_index,player_surface
    if player_rect.bottom == 300:
        player_index += 0.1
        player_surface = player_walk[int(player_index)]
        if player_index >= 1.5: player_index = 0
    else:
        player_surface = player_jump
pygame.init()
screen = pygame.display.set_mode((800,400))
pygame.display.set_caption("PyRunner")
clock = pygame.time.Clock()
#game variables
start_time = 0
game_active = False
score = 0
#######
player  = pygame.sprite.GroupSingle()
player.add(Player())
player_gravity = 0
# import images
font = pygame.font.Font("font/Pixeltype.ttf",50)
Sky_surface = pygame.image.load("graphics/Sky.png").convert()
ground_surface = pygame.image.load("graphics/ground.png").convert()
##### 
player_stand = pygame.image.load("graphics/Player/player_stand.png").convert_alpha()
player_stand= pygame.transform.rotozoom(player_stand,0,2 )
player_stand_rect = player_stand.get_rect(center=(400,200))
player_walk1 = pygame.image.load("graphics/Player/player_walk_1.png").convert_alpha()
player_walk2 = pygame.image.load("graphics/Player/player_walk_2.png").convert_alpha()
player_walk = [player_walk1,player_walk2]
player_index = 0
player_jump = pygame.image.load("graphics/Player/jump.png").convert_alpha()
player_surface = player_walk[player_index]
player_rect = player_surface.get_rect(midbottom=(80,300))
player_gravity = 0 
#####
snail_frame1 = pygame.image.load("graphics/snail/snail1.png").convert_alpha()
snail_frame2 = pygame.image.load("graphics/snail/snail2.png").convert_alpha()
snail_frames = [snail_frame1,snail_frame2]
snail_index = 0
snail_surface = snail_frames[snail_index]

fly_frame1 = pygame.image.load("graphics/fly/fly1.png").convert_alpha()
fly_frame2 = pygame.image.load("graphics/fly/fly2.png").convert_alpha()
fly_frames = [fly_frame1,fly_frame2]
fly_index = 0  
fly_surface = fly_frames[fly_index]
obstacle_rect_list = []
#####
game_name = font.render("PyRunner",False,(111,196,169))
game_name_rect = game_name.get_rect(center=(400,80))

game_message = font.render("Press space to start",False,(111,196,169))
game_message_rect = game_message.get_rect(center=(400,330))

#timers
obstacle_timer = pygame.USEREVENT + 1
pygame.time.set_timer(obstacle_timer,1500)

snail_animation_timer = pygame.USEREVENT + 2
pygame.time.set_timer(snail_animation_timer,500)

fly_animation_time = pygame.USEREVENT + 3
pygame.time.set_timer(fly_animation_time,200)

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
            if event.type == obstacle_timer:
                if randint(0,2):
                    obstacle_rect_list.append(snail_surface.get_rect(bottomright=(randint(900,1100),300)))
                else:
                    obstacle_rect_list.append(fly_surface.get_rect(bottomright=(randint(900,1100),200)))
            if event.type == snail_animation_timer:
                if snail_index == 0:
                    snail_index = 1
                else:
                    snail_index = 0
                snail_surface = snail_frames[snail_index]
            if event.type == fly_animation_time:
                if fly_index == 0:
                    fly_index = 1
                else:
                    fly_index = 0
                fly_surface = fly_frames[fly_index]
        else:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                start_time = pygame.time.get_ticks()
                game_active = True
        
    
    if game_active:
        #score
        #background
        screen.blit(ground_surface,(0,300))
        screen.blit(Sky_surface,(0,0))
        #player
        player_gravity += 1
        player_rect.y += player_gravity
        if player_rect.bottom >= 300:player_rect.bottom = 300
        player_animation()
        screen.blit(player_surface,player_rect)
        player.draw(screen)
        player.update()
        # obstacle movment
        obstacle_rect_list=obstacle_movement(obstacle_rect_list)
        score = display_score()
        #collision
        game_active = collision(player_rect,obstacle_rect_list)
    else:
        screen.fill((94,129,162))
        screen.blit(player_stand,player_stand_rect)
        obstacle_rect_list.clear()
        player_rect.midbottom = (80,300)
        player_gravity=0
        if score == 0:
            screen.blit(game_name,game_name_rect)
            screen.blit(game_message,game_message_rect)
        else:
            score_surface = font.render(f'Your score: {score}',False,(111,196,169))
            score_rect = score_surface.get_rect(center=(400,330))
            screen.blit(score_surface,score_rect)
    pygame.display.update()
    clock.tick(60)