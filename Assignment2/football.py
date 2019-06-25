#Name:Hanwen Zhao
#Recitation 106
#TA Madhumitha Soundararajan
#Assignment #2
#Problem #1
#Football: Calculate the Passer Rating

completions = int(input("Please input the pass completion number for the quarterback."))
attempts = int(input("Please input the pass attempt number for the quarterback."))
yards = int(input("Please input the total passing yard number for the quarterback."))
touchdowns = int(input("Please input the touchdown number for the quarterback."))
interceptions = int(input("Please input the interception number for the quarterback."))    #User inputs data

print ("The pass completion number for the quarterback is ",completions,".")
print ("The pass attempts number for the quarterback is ",attempts,".")
print ("The pass total passing yards number for the quarterback is ",yards,".")
print ("The touchdown number for the quarterback is ",touchdowns,".")
print ("The interception number for the quarterback is ",interceptions,".")    #Repeat the data from user's input

C = float((completions/attempts - 0.30)*5)
Y = float((yards/attempts -3)*0.25)
T = float((touchdowns/attempts)*20)
I = float((2.375 - (interceptions/attempts)*25))  # Calculating C Y T I accroding to the equations

if C < 0:
	C = 0
if Y < 0:
	Y = 0
if T < 0:
	T = 0
if I < 0:
	I = 0                        #If C,Y,T, or I is less than 0, then set it to 0

if C > 2.375:
	C = 2.375
if Y > 2.375:
	Y = 2.375
if T > 2.375:
	T = 2.375
if T > 2.375:
	T = 2.375                     #If C,Y,T,or I is greater than 2.375, then set it to 0
	
print (C,Y,T,I)
	
passerrating = float (format (((C+Y+T+I)/6*100),'.2f'))  #Calculating the passerrating according to the equation

if passerrating <= 85:
	print("Rating ",passerrating,", this is poor.")
elif passerrating > 85:
	print("Rating ",passerrating,", this is mediocre.")
elif passerrating > 90:
	print("Rating ",passerrating,", this is good.")
elif passerrating > 95:
	print("Rating ",passerrating,", this is great.")       #A rating is "poor" if the it is 85 or below, "mediocre" if above 85, "good" if above 90. "great" if above 95.
