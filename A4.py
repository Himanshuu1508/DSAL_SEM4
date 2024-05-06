def create_set():
    my_set = []
    print("\nEnter Numbers separated by spaces:")
    numbers = input().split()  # Split input by spaces
    for num in numbers:
        my_set.append(int(num))
    return my_set

def Add_Element(A, num):
    pos = int(input("\nEnter the position at which you want to insert the element: "))
    A.insert(pos, num)
    print(A)

def Remove_Element(A, num):
    if num in A:
        A.remove(num)
        print(A)
    else:
        print("Element not in the set")

def Union_Function(setA, setB):
    C = list({i: i for i in setA + setB}.values())
    print("Union set: ", C)

def Intersection_Function(setA, setB):
    C = [i for i in setA if i in setB]
    print("Intersection set: ", C)

def Difference_Function(setA, setB):
    C = [element for element in setA if element not in setB]
    print("Difference Set: ", C)

def Contains_Element(A, num):
    return num in A

def Size_of_Set(A):
    return len(A)

def Subset_Function(A, B):
    if all(i in A for i in B):
        print("\n Yes, Subset Exists")
    else:
        print("\n No, Subset Does not exists")

# Driver Code
A = set()
print("\n Create set A")
A = create_set()
print("A = ", A)
B = set()
print("\n Create set B")
B = create_set()

while True:
    print("\nMain Menu")
    print("1. Add an element to the set A")
    print("2. Add an element to the set B")
    print("3. Remove an element from the set A")
    print("4. Remove an element from the set b")
    print("5. Membership Of element")
    print("6. Size of the Set")
    print("7. Union")
    print("8. Intersection")
    print("9. Difference")
    print("10. Check subset")
    print("11. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        num = int(input("Enter element to be added in this set: "))
        Add_Element(A, num)
    elif choice == "2":
        num = int(input("Enter element to be added in this set: "))
        Add_Element(B, num)
    elif choice == "3":
        num = int(input("Enter element to be removed from this set: "))
        Remove_Element(A, num)
    elif choice == "4":
        num = int(input("Enter element to be removed from this set: "))
        Remove_Element(B, num)    
    elif choice == "5":
        num = int(input("Enter the number to be searched from the set:"))
        if Contains_Element(A, num):
            print("The element is present in the set.")
        else:
            print("The element is not present in the set.")
    elif choice == "6":
        print("The size of the set is:", Size_of_Set(A))
    elif choice == "7":
        Union_Function(A, B)
    elif choice == "8":
        Intersection_Function(A, B)
    elif choice == "9":
        Difference_Function(A, B)
    elif choice == "10":
        Subset_Function(A, B)
    elif choice == "11":
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please choose again.")
