principal = input("Please input your principal amount  ") #User inputs principal
print "Your ptincipal amount is   " + str(principal)

duration = input("Please input your duration(years)   ") #User inputs duration
print "Your ptincipal amount is   " + str(principal)
print "Your duration is   " + str(duration) + "  years"

interestrate = input("Please input your interest rate(number only)  ") #User inputs interest rate
print "Your ptincipal amount is   " + str(principal)
print "Your duration is   " + str(duration) + "  years"
print "Your interst rate is   " + str(interestrate) + "%"

interest = principal * duration	* interestrate /100   #Calculating simple interest
print "The simple interest is  " + str (interest) + "." #Output the result

#Programming in version 2.7.6
