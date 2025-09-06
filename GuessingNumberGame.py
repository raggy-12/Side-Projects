#GuessingNumberGame
#John Kimak
#September 19th, 2024
import random
import time
from utility import *

def main():
    #Initialize Variables
    now = time.time_ns()
    random.seed(now)
    
    secretNumber = random.randint(1,100)
    guessCount = 0
    maxGuesses = 5
    

    #Ask for name & if you want to play the game
    name = input("Hi, what is your name? ")
    print("Hi, nice to meet you", name)
    wantToGame = input("Want to play a game? Y/N: ")
    
    #Quits if you reply with no
    if(wantToGame == "N" or wantToGame == "n"):
        print("Ok thank you for your time, goodbye")
        quit
    else:
        print("Error: reply with Y or N")
        quit
    
    #Continues game if you say yes
    if(wantToGame == "Y" or wantToGame == "y"):
        while guessCount < maxGuesses:
            guess = int(input("Guess a number between 1 & 100: "))
            if guess < secretNumber:
                guessCount +=1
                print("Too low, guess again. You have",  maxGuesses - guessCount, "guesses remaining" + "\n")
            elif guess > 100:
                print("Enter a valid number between 1 & 100" + "\n")
            elif guess > secretNumber:
                guessCount +=1
                print("Too high, guess again. You have", maxGuesses - guessCount, "guesses remaining" + "\n")
            elif guess == secretNumber:
                print("Congratulations! You win!")
                break
            if guessCount == maxGuesses:
                print("You lose, the secret number was: ", secretNumber)
                break
        None
main()

   