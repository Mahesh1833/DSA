n = int(input("Enter the number of records: "))
hashTable = [[] for i in range(n)]

# FUNCTION FOR LINEAR PROBING
def linearProbing(val, name, phone):
    while hashTable[val]:
        val = (val + 1) % n
    hashTable[val] = [(name, phone)]
    displayHashTable()

# FUNCTION FOR SEPARATE CHAINING
def separateChaining(val, name, phone):
    hashTable[val].append((name, phone))
    displayHashTable()

def insertValue(name, phone):
    val = phone % n
    if not hashTable[val]:
        hashTable[val] = [(name, phone)]
    else:
        print("\n***** Collision Occurred ******")
        choice = int(input('1. Linear Probing\n2. Separate Chaining\n'))
        if choice == 1:
            linearProbing(val, name, phone)
        elif choice == 2:
            separateChaining(val, name, phone)

def displayHashTable():
    for i in range(n):
        print(str(i) + " -> " + str(hashTable[i]))

def searchNum(phone):
    for i in range(n):
        for name, num in hashTable[i]:
            if num == phone:
                print(f'Element Found! : {name}')
                return
    print("Not found")

# Insert records
print("Enter records:")
for i in range(n):
    name = input("Enter the name: ")
    phone = int(input("Enter the phone number: "))
    insertValue(name, phone)

# Search menu
while True:
    print("\nMenu:")
    print("1. Search an element")
    print("2. Exit")
    option = int(input("Choose an option: "))
    if option == 1:
        insEle = int(input("Enter the number of phone numbers you want to search: "))
        for i in range(insEle):
            phone = int(input("Enter the phone number to be searched: "))
            searchNum(phone)
    elif option == 2:
        break
    else:
        print("Invalid option")
