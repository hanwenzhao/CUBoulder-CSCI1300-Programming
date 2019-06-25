#Name:Hanwen Zhao
#Recitation 106
#TA Madhumitha Soundararajan
#Assignment #2
#Problem #2
#Football: Cycling: Power and Energy

#2
M = float(input("Please input the mass if the rider in Kg."))
Mb = float(input("Please input the mass if the bike in Kg."))
v = float(input("Please input the velocity in m/s."))
Cf = float(input("Please input the cofficient of drafting."))
g = float(9.8)
k = float(0.18)
Cr = float(0.001)              #user input data

Pa = float(k * Cf * v**3)        #Calcuate P air

Pr = float(Cr * g * (M + Mb) * v)  #Calcuate P roll

Ps = round(Pa + Pr)  #Calcuate a round result of P sec

print("The total power output per second is around",Ps,"W.")  #The result of the first part of the question should be 167 W.


#3
d = float(input("Plaese input the distance in kilometers.")) # user input the distance

t = float((d * 1000)/v)  #calcuate the time in seconds

Et = round((Ps * t)/1000) #calcuate the total energy

print("The total energy is around ",Et, "kJ.")

#4
import random

tm = round(t/60)  # cover time into minutes

x = tm

iE = 0

mm = 1

while x != 0:    #set up a while loop. Starts with the minutes x. 
	rCf = random.uniform(0.50,1.0) #everytime the random module will generating a random number between 0.50 and 1.0.
	Pa = float(k * rCf * v**3) #calcuate P air with new Cf draft
	Pr = float(Cr * g * (M + Mb) * v)
	Ps = round(Pa + Pr)
	Et = round((Ps * 60 * 1)/1000) #calcuate the energy for this minute
	x -= 1 #everytime the x = x-1 decrease
	iE = iE + Et #the total energy so far
	print("At the #",mm," minute(s). The energy total so far is ",iE," kJ.")
	mm += 1  #output the result

aE = iE / tm  #calcuate the average result


print("The average energy is ", aE," kJ.")	
	
















