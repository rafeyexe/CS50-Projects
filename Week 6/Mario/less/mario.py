from cs50 import get_int
space = ' '
sym='#'
while 1:
    height= get_int('height: ')
    if height < 1 or height > 8:
        height = get_int('height: ')
    if height >= 1 or height <= 8:
        break
    height=get_int("Enter height from 1 to 8: ")
for i in range(height):
    print((height-1-i) * space,end="")
    print((i + 1)*sym)