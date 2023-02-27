import random

def play_game():
    options = ['rock', 'paper', 'scissors']
    computer_choice = random.choice(options)
    print(f"The computer chose {computer_choice}.")
    
    user_choice = input("Enter your choice (rock, paper, scissors): ").lower()
    if user_choice not in options:
        print("Invalid choice, try again.")
        play_game()
        
    if (user_choice == 'rock' and computer_choice == 'scissors') or \
       (user_choice == 'paper' and computer_choice == 'rock') or \
       (user_choice == 'scissors' and computer_choice == 'paper'):
        print("You win!")
    elif user_choice == computer_choice:
        print("It's a tie.")
    else:
        print("You lose.")
        
play_game()
