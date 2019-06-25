#!/usr/bin/env	python
#Name:Hanwen Zhao
#Recitation 106
#TA Madhumitha Soundararajan
#Assignment #6
import sys
from geopy.geocoders import OpenMapQuest
from geopy.distance import vincenty
from geopy import Point
geolocator = OpenMapQuest()

def main():             #main function
    #filename = "cityList.txt"   #easy to debug
    filename = sys.argv[1]       #read the first argument as the file name
    fo = open(filename,"r")     #open file
    line = fo.readline      #read line in file
    cityList = []        #create a blank list
    pointDictionary = {}  #create a blank dictionary
    waypointList = []    #create a blank list
    for line in fo:   #for each line in fo
        address,(latitude,longitude) = geolocator.geocode(line)    #use geolocator to get its latitude and longitude
        pointDictionary[line.rstrip()] = Point((latitude,longitude))  #store the city name as the key, coordinates as the value in the point dictionary
        cityList.append(line.rstrip())  #also add city names in the citylist
    currentCity = cityList[0]  #set the first city in the file as the startlocation
    cityList.remove(currentCity)  #remove the startlocation from city list
    waypointList = calculateTheWayPoint(currentCity,cityList,pointDictionary,waypointList)  #call calculatewaypoint function and return the waypointlist
    totalDistance = calculateTotalDistance(currentCity,waypointList,pointDictionary)  #call calculate total distance function and get the total distance
    waypointList.insert(0,currentCity)  #add the startlocation into the waypoint list  for output
    totalDistance = totalDistance + vincenty((pointDictionary[currentCity]),(pointDictionary[waypointList[len(waypointList)-1]])).miles #add the distance from the last waypoint back to the startlocation
    print waypointList  #print the waypointlist
    print totalDistance  #print the total distance
    fo.close()  #close the file
    
    
def calculateTheWayPoint(currentCity,cityList,pointDictionary,waypointList):  #calculate the waypoint
    distance = 0
    distanceDictionary = {}  #create the blank distance blank dictionary
    while len(cityList) != 0:     #while loop for repeat searching
        for item in cityList:    
            distanceDictionary[item] = vincenty((pointDictionary[currentCity]),(pointDictionary[item])).miles  #for each item in the citylist, use item as the key, distance to other cities as the value
        cloestCity = min(distanceDictionary,key = distanceDictionary.get)  #find the min value in the dictionary, the item is the cloest city
        distanceDictionary = {}  #clean the distance dictionary
        currentCity = cloestCity #set the cloest city as the current city
        cityList.remove(cloestCity)  #remove the cloest city from city list
        waypointList.append(cloestCity)  #add the cloest city to the waypoint
    return waypointList  #return the waypoint
    
    
def calculateTotalDistance(currentCity,waypointList,pointDictionary): #calculate the total distance function
    totalDistance = 0
    for item in waypointList: 
        distance = vincenty((pointDictionary[currentCity]),(pointDictionary[item])).miles #for each city in the waypoint list, calculate the distance between current city and next waypoint
        currentCity = item  #set waypoint as current city
        totalDistance = totalDistance + distance  #add distance to the total distance
    return totalDistance  #return total distance
    
main()
    
