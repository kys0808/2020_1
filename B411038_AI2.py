#1
pizza = ['peperoni','hawaian','supreme']
for i in pizza:
    print(i)

#2
pets = ['dog','cat','dog','goldfish','cat','rabbit','cat']
while 'cat' in pets:
    pets.remove('cat')
print (pets)

#3
num1_9 = [value for value in range(1,10)]
for i in num1_9:
    if i == 1:
        print (str(i) + 'st')
    elif i == 2:
        print (str(i) + 'nd')
    elif i == 3:
        print (str(i) + 'rd')
    else:
        print (str(i) + 'th')

# 4.1
new_users = ['admin','jake','maty','ronny','andy']
current_users = ['admin','dan','angie','maty','sharelle','rhoda']

for user in new_users:
    if user in current_users:
        print (user + " has been already taken")
#4.2
    else:
        current_users.append(user)


print (current_users)
print (new_users)

#4.3
for user in current_users:
    if user in new_users:
        new_users.remove(user)

print(new_users)
