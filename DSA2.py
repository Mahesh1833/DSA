# Input elements for list 1 and convert to set
list1 = input("Enter elements for list 1 separated by spaces: ").split()
set1 = set(map(int, list1))

# Input elements for list 2 and convert to set
list2 = input("Enter elements for list 2 separated by spaces: ").split()
set2 = set(map(int, list2))
# 1] Union
def union(set1, set2):
    return set1 | set2

# 2] Intersection
def intersection(set1, set2):
    return set1 & set2

# 3] Difference
def difference(set1, set2):
    return set1 - set2

# 4] Symmetric Difference
def symmetric_difference(set1, set2):
    return set1 ^ set2

# 5] Subset
def is_subset(set1, set2):
    return set1 <= set2

# 6] Remove
def remove_element(set1, element):
    if element in set1:
        set1.remove(element)
    return set1

# 7] Add
def add_element(set2, element):
    set2.add(element)
    return set2

# 8] Size
def set_size(set1):
    return len(set1)

# 9] Iterate
def iterate_set(set1):
    for element in set1:
        print(element)

# Function to display menu
def display_menu():
    print("\nSet Operations Menu:")
    print("1. Union")
    print("2. Intersection")
    print("3. Difference")
    print("4. Symmetric Difference")
    print("5. Subset")
    print("6. Remove Element")
    print("7. Add Element")
    print("8. Size")
    print("9. Iterate")
    print("0. Exit")


# Main program
while True:
    display_menu()
    choice = int(input("Enter your choice (0-9): "))

    if choice == 0:
        print("Exiting...")
        break
    elif choice == 1:
        print("Union:", union(set1, set2))
    elif choice == 2:
        print("Intersection:", intersection(set1, set2))
    elif choice == 3:
        print("Difference (set1 - set2):", difference(set1, set2))
    elif choice == 4:
        print("Symmetric Difference:", symmetric_difference(set1, set2))
    elif choice == 5:
        print("Is set1 a subset of set2:", is_subset(set1, set2))
    elif choice == 6:
        element = int(input("Enter the element to remove from set1: "))
        print("Set1 after removing element {}:".format(element), remove_element(set1.copy(), element))
    elif choice == 7:
        element = int(input("Enter the element to add to set2: "))
        print("Set2 after adding element {}:".format(element), add_element(set2.copy(), element))
    elif choice == 8:
        print("Size of set1:", set_size(set1))
        print("Size of set2:", set_size(set2))
    elif choice == 9:
        print("Elements of set1:")
        iterate_set(set1)
    else:
        print("Invalid choice! Please enter a number between 0 and 9.")
