print "There is a birth every 7 seconds."
print "There is a death every 13 seconds."
print "There is a new immigrant every 35 seconds."
print "The current U.S. population is 307,357,870."
print "Now calculating the U.S. popluation in excatly one year (365days)" #Describe the function of the program

secinyear = 60*60*24*365   #Calculate the seconds of a year

birth = secinyear/7        #Calculate the population of bith in a year

death = secinyear/13       #Calculate the population of death in a year

immigrant = secinyear/35   #Calculate the population of immigrant in a year

population = int (307357870 + birth - death + immigrant)  #Calculate the future population by current population + birth - death + immigrant

print ("The population will be " + str(population) +".")  #Output the result

#Programming in version 2.7.6
