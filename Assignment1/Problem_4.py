totalsec = input ("Input time of seconds to convert (0~86400). ") #User input the number of seconds to convert

h = totalsec/(60*60)   #Conver to hours

m = (totalsec%(60*60))/60  #Use the remainder from hours to calculate minuates

s = (totalsec%(60*60))%60  #Use the remainder from minuates to calculate seconds

print "The time is " + str(h) + " hours, " + str(m) + " minutes, " + str(s) + " seconds." #Output the result

#Programming in version 2.7.6
