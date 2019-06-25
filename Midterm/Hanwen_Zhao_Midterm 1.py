#Name:Hanwen Zhao
#Recitation 106
#TA: Madhumitha Soundararajan
#Midterm #1

import csv
def main():
    
    f = futureValue()  #call futureValue function
    print("The future value will be", f,".")   #print the furture value
    
    a = int(input("How many Class A seats tickets were sold? "))  #ask user to input how many ticket were sold in each category
    b = int(input("How many Class B seats tickets were sold? "))
    c = int(input("How many Class C seats tickets were sold? "))
    income = calcIncome(a, b, c)      #call calcincome function
    print("The total income will be", income,".")  #print total income
    
    
    
    hotList = listHotDays()   #call listhotdays function
    for item in hotList:      #print hot days
        print("The hot days were",item,".")
    
    
def futureValue():  #define futureValue function
    p = float(input("Please enter the present value of the account. "))  #ask user to input p t and interest
    t = int(input("Please enter the number of the months. "))
    interest = float(input("Please enter the interest rate. "))
    f = format(p * (1 + interest) ** t, ".2f")   #claculate the future value
    return f                         #return the value


def calcIncome(A, B, C):      #def calciuncome function
    income = A * 20 + B * 15 + C * 10   #calculate the income  
    return income       #return the value
    
    
def listHotDays():     #def the listhotdays function
    fo = open("BoulderWeatherData.csv","r")   #openthe file
    dataList = []   #create the datalist
    hotList = []   #create the hotlist
    l = 0
    for line in fo:
        if l > 0:
            dataList = line.split(",")   #split the line
            l = l + 1
    if int(dataList[2]) >= 95:    #if the temp higher than 95  add date into list
        hotList.append(dataList[0])
        

        

    return hotList   #return the value
        
        
main()
