from csv import reader, DictReader
from sys import argv, exit
def main():
    if len(argv)!=3:
        print("Incorrect usage")
    database=argv[1]
    dna=argv[2]
    max_repeats=[]

    with open(database,'r') as csvfile:
        reader = DictReader(csvfile)
        csv_dict = list(reader)

    with open(dna,'r') as file:
        sequence = file.read()

    for i in range(1, len(reader.fieldnames)):
        STR = reader.fieldnames[i]
        max_repeats.append(0)

        for j in range(len(sequence)):
            STRcount=0
            if sequence[j:(j + len(STR))] == STR:
                repeat = 0

                while sequence[(j + repeat):(j + repeat + len(STR))] == STR:
                    STRcount += 1
                    repeat += len(STR)

                    if STRcount > max_repeats[i - 1]:
                        max_repeats[i - 1] = STRcount

    for i in range(len(csv_dict)):
        matches=0
        for j in range(1, len(reader.fieldnames)):

            if int(max_repeats[j - 1]) == int(csv_dict[i][reader.fieldnames[j]]):
                matches += 1

            if matches == (len(reader.fieldnames) - 1):
                print(csv_dict[i]['name'])
                return(0)
    print("No match")
main()