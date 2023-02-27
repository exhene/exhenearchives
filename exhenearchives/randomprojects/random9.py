import sys
import pygame

# Initialize the game library
pygame.init()

# Set up the display
screen = pygame.display.set_mode((800, 600))

# Start the game loop
running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Clear the screen
    screen.fill((0, 0, 0))

    # Draw the ball
    pygame.draw.circle(screen, (255, 255, 255), (400, 300), 20)

    # Draw the paddles
    pygame.draw.rect(screen, (255, 255, 255), (20, 250, 20, 100))
    pygame.draw.rect(screen, (255, 255, 255), (760, 250, 20, 100))

    # Update the display
    pygame.display.update()

# Quit the game library
pygame.quit()
sys.exit()
