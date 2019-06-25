#Name:Hanwen Zhao
#Recitation 106
#TA Madhumitha Soundararajan
#Assignment #3
import random

userName = input("Please enter your name: ")                #ask user to enter their name
print ("Hello, ",userName,". Welcome to the Dungeon Game. If you want to exit the game, please enter 'quit'.")  #introduction

lobby = "lobby"                                                      #define the value
kitchen = "kitchen"
furnace = "furnace"
hallway = "hallway"
basement = "basement"
limbo = "limbo"
grave = "grave"
dragoncave = "dragoncave"
princessroom = "princessroom"
randomroom = "randomroom"
gate = "gate"
lock = "lock"
sword = False
command = ""

current = "gate"                                                    #user begin the game at the gate

while command != "quit":                                            #if the input is not "quit", enter the while loop
	if current == gate:
		command = input("There is a huge gate in front of you, do you want to walk in to(y), or leave(n)?")
		if command == "y":                                          #selection of y or n
			current = lobby
		elif command == "n":
			break
		else:                                                       #if user enter something is not y or n, back to the gate
			current = gate
	elif current == lobby:                                           #enter the room lobby
		command = input("You are in the lobby, there are doors to the north(n),south(s),west(w), and east(e).")
		if command == "n":                                          #there are four rooms connected to the lobby
			current = gate
		elif command == "s":
			current = hallway                                        #connect to room hallway
		elif command == "w":
			current = furnace                                        #connect to room furnace
		elif command == "e":
			current = kitchen                                        #connect to room kitchen
		else:
			current = lobby                                        #if user enter something is not y or n, back to the lobby
	elif current == "furnace":
		print("You entered the Furnace and fry yourself to death! Game Over.")  #enter the furnace, game over
		break
	elif current == kitchen:                                         #in the kitchen, user find the password from letter.txt
		fo = open("letter.txt","r")
		password =fo.readline()
		print("You find a letter in the kitchen, it says ",password)
		command = input("You are in the kitchen, there is a door to the west(w).")
		if command == "w":                                          #connect to room lobby
			current = lobby
		else:
			current = kitchen                                       #if user enter something else, stay at kitchen
	elif current == hallway:                                          #at the room hallway
		command =input("You are in the hallway, there are the doors to the north(n), and south(s).")
		if command == "n":                                         #connect to the lobby
			current = lobby
		elif command == "s":                                        #connect to the lock door
			current = lock
		else:
			current = hallway
	elif current == lock:
		command = input("The door to the south is locked. It needs a password. Please entery the password.")
		fo = open("letter.txt","r")
		password =fo.readline()
		done = 0
		if int(command) == int(password):                           #compare the user input and the password from letter
			current = basement
		else:
			while not done:
				command = input("The password is wrong, please try again or give up(n)")   #if the use don't know the password, they can go back
				if int(command) == int(password):
					current = basement
					done = 1
					break
				elif command == "n":
					current = hallway
					done = 1
					break
	elif current == basement:                                                 #there are four rooms connect to the basement
		command = input("The password is correct! You are in the basement, there are doors to the north(n),south(s),west(w),east(e).")
		if command == "n":
			current = hallway
		elif command == "s":
			current = dragoncave
		elif command == "w":
			current = randomroom
		elif command == "e":
			current = limbo
		else:
			current = basement
	elif current == randomroom:                                             #the randomroom will send user to a random room other than basement
		print("You enter a magic portals, you will be sent to a random room.")
		n = random.randint(1,8)                                              #user enter different rooms
		if n == 1:
			current = lobby
		elif n == 2:
			current = furnace
		elif n == 3:
			current = kitchen
		elif n == 4:
			current = hallway
		elif n == 5:
			current = basement
		elif n == 6:
			current = limbo
		elif n == 7:
			current = dragoncave
		elif n == 8:
			current = princessroom
	elif current == limbo:                                            #in the room limbo, user find a sword, without the sword, they cannot kill the dragon
		print("You find a sword in the limbo.")
		sword = True
		command = input("You are in the limbo, there is a door to the west(w).")
		if command == "w":
			current = basement
		else:
			current = limbo
	elif current == dragoncave:                                       #with the sword, they can kill the dragon
		print("You enter a dragon cave, there is a dragon.")
		if sword == True:
			print("You have a sword with you, you kill the dragon.")
			command = input("There is a door to the south(s).")
			if command == "s":
				current = princessroom
		elif sword == False:                                        #if the user do not have a sword, they can go back to find it
			command = input("You don't have a weapon with you. Do you want to fight with dragon(f), or run away(n)?")
			if command == "f":                                      #they will be killed by dragon if they fight without a sword
				print("You were killed by dragon. Game Over.")
				break
			elif command == "n":
				current = basement
		else:
			current = dragoncave
	elif current == princessroom:                                     #find the princess, game over
		print("You find the princess, you are the hero!")
		break
				
		
print("Goodbye.")
