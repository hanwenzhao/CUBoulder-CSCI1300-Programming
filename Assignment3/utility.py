i = 0
fo = open("Hanwen_Zhao_Assignment#3.py","r")
line = fo.readlines()
t = len(line)
for x in range(0,t):
	linen = line[x]
	if linen.startswith("#") !=True and linen.strip()!='':
		i = i + 1
print("The number of lines is ",i)
