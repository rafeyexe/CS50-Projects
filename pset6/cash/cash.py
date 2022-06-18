from cs50 import get_float
change=0
owed=0
while 1:
    money = get_float("Change: ")
    if money>0:
        break
change=round(money*100)
while change>0:
    if change>=25:
        owed+=1
        change-=25
    elif change>=10:
        owed+=1
        change-=10
    elif change>=5:
        owed+=1
        change-=5
    elif change>=1:
        change-=1
        owed+=1
print(owed)