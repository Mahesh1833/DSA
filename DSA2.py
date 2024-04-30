A = []
n = int(input("Enter the number of students in the set1: "))
for i in range(n):
    ele = int(input("Enter roll no of students in the set1: "))
    A.append(ele)
print("List of students in the class is:", A)

B = []
for i in range(5):
    ele = int(input("Enter roll no of students in the set2: "))
    B.append(ele)
print("List of students in the class is:", B)

set1 = set(A)
set2 = set(B)

# MENU DRIVEN
print("Enter which operation do you want to perform:")
print("""1] Union
2] Intersection
3] Difference
4] Symmetric Difference
5] Subset
6] Remove
7] Add
8] Size
9] Iterate""")

flag = True
while flag:
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("Union of two sets is:", set1.union(set2))

    elif choice == 2:
        print("Intersection of two sets is:", set1.intersection(set2))

    elif choice == 3:
        e = input("Enter set from which set to subtract: ")
        if e == 'set1':
            print("Difference of set1 - set2 is:", set1.difference(set2))
        else:
            print("Difference of set2 - set1 is:", set2.difference(set1))

    elif choice == 4:
        e = input("Enter set from which set to subtract: ")
        if e == 'set1':
            print("Symmetric difference of set1 & set2 is:", set1.symmetric_difference(set2))
        else:
            print("Symmetric difference of set2 & set1 is:", set2.symmetric_difference(set1))

    elif choice == 5:
        if set1.issubset(set2):
            print("Set1 is subset of set2.")
        else:
            print("Set2 is subset of set1.")

    elif choice == 6:
        e = input("Enter set from which set to remove element: ")
        f = int(input("Enter element which you want to remove: "))
        if e == 'set1':
            set1.remove(f)
        else:
            set2.remove(f)

    elif choice == 7:
        e = input("Enter set in which you want to add element: ")
        f = int(input("Enter element which you want to add: "))
        if e == 'set1':
            set1.add(f)
        else:
            set2.add(f)

    elif choice == 8:
        e = input("Enter set whose length do you want to find: ")
        if e == 'set1':
            print("Size of set1 is", len(set1))
        else:
            print("Size of set2 is", len(set2))

    elif choice == 9:
        e = input("Enter set from which you want to iterate: ")
        if e == 'set1':
            print("Elements of set1 are:", A)
        else:
            print("Elements of set2 are:", B)

    else:
        print("Invalid choice")

    abc = input("Do you want to continue? (yes/no): ")
    if abc.lower() != "yes":
        flag = False
