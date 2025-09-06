#card_deck
#John Kimak
#26 Sept 2024
#Building and manipulating a deck of cards

import random

# Define suits and faces
suits = ["Hearts", "Diamonds", "Clubs", "Spades"]
faces = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"]

deck = [i for i in range(52)]

def face_name(card):
    #Determine suit
    suit = suits[card // 13]
    #Determine face
    face = faces[card % 13] 
    return f"{face} of {suit} "

None

def main():
    index = 0
    for card in deck:
        print(face_name(card), end="  ")
        index += 1
        # Print a newline after every 13 cards
        if index % 13 == 0:
            print("")
None
random.shuffle(deck)
main()
