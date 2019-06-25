#Name:Hanwen Zhao
#Recitation 106
#TA Madhumitha Soundararajan
#Assignment #4

import csv #import csv BIF
def CreatDictionary(name):  #create a function to create a dictiondry
	dictionary = {}         #create a blank dictionary
	fo = open(name,"r")     #open the file
	reader = csv.reader(fo) #rease the file
	
	for row in reader:      
		dictionary[row[0]] = row[1]   #for each row in file, read seachKey from row[0], read the value from row[1]
	return dictionary       #return dictionary to the main function
	
def main():               #main function
	done = 0
	Ot = str()            #a blank string for output
	wordDictionary = CreatDictionary("textToEnglish2014.csv")  # call creatdictionary function
	while not done:                                            #while loop
		userInput = str.split(str.lower(input("Please input one or more text abbreviations separated by a space.")))   #covert user input into a list
		for item in userInput:                               #for each item in the list
			userOutput = str(searchDictionary(wordDictionary, item))   # call searchDictionary function covert item in the list into string
			Ot =str(Ot) + " " + userOutput               #final output
		print(Ot)
		command = input("Do you want to play again(y), or quit(q)?")   #ask user if they want to play again
		if command == "y":                 #if command is y countine the loop
			done = 0
		elif command == "q":              #if command is q quit
			done = 1
		
	
def searchDictionary(dictionary, searchKey):   #searchDictionary function                               
	if searchKey in dictionary:
		val = dictionary[searchKey] #val is the value of the searchkey if searchKey is in the dictionary
	else:
		val = "NF"              #val is NF if the searchKey not in the dictionary
	return val
	
main()
	
