print "The Great Lakes in the United States contain roughly 22% of the world's fresh water (22,810 km^3)."
print "Calculate how deep it would be if all the water in the Great Lakes were spread evenly across the 48 contiguous U.S. states."
print "The area of the 48 contigous U.S. states is 8,080,464.3 km^2" #Describe the problem

x = format ((22810 / 8080464.3) * 1000, '.2f')  #Calculate the depth of the water and put the result in two decimal place

print "The depth is " + str(x) + " meters." #Out put the result

#Programming in version 2.7.6
