from cs50 import get_string
text=get_string("Enter text:\n")
letters=0
words=0
sentences=0
for i in range(len(text)):
    if (text[i]>='a' and text[i]<='z') or (text[i]>='A' and text[i]<='Z'):
        letters+=1
    elif (text[i]=='.' or text[i] == '!' or text[i] == '?'):
        sentences+=1
    words=(len(text.split()))
# print(letters, words, sentences)
L = ((letters/words)*100)
S = (100*(sentences/words))
grade = 0.0588 * L - 0.296 * S - 15.8
# print(grade)
if (grade < 16 and grade >= 0):
    print("Grade",round(grade))
elif (grade>=16):
    print("Grade 16+")
else:
    print("Before Grade 1")