class Node:
    def __init__(self, name, no):
        self.name = name
        self.no = no
        self.used = False

class Hashtable:
    def __init__(self):
        self.data = []
        for i in range(10):
            self.data.append(Node(None, None))

    def hashfunc(self, name):
        s = 0
        for c in name:
            s += ord(c)
        return s % 10

    def quadprobing(self, key):
        i = 1
        while self.data[key].used != False:
            key = (key + (i * i)) % 10
            i += 1
        print("Combinations required:", i)
        return key

    def linprobing(self, key):
        i = 1
        while self.data[key].used != False:
            key = (key + 1) % 10
            i += 1
        print("Combinations required:", i)
        return key

    def lininsert(self, name, no):
        key = self.hashfunc(name)
        key = self.linprobing(key)
        self.data[key] = Node(name, no)
        self.data[key].used = True

    def quadinsert(self, name, no):
        key = self.hashfunc(name)
        key = self.quadprobing(key)
        self.data[key] = Node(name, no)
        self.data[key].used = True

    def search(self, name):
        key = self.hashfunc(name)
        index = key
        while self.data[index].used:
            if self.data[index].name == name:
                print("Found. No is:", self.data[index].no)
                return
            index = (index + 1) % 10
            if index == key:
                break
        print("Not found")

def print_menu():
    print("\nMenu:")
    print("1. Linear Insert")
    print("2. Quadratic Insert")
    print("3. Search")
    print("4. Exit")

def main():
    hashtable = Hashtable()
    while True:
        print_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            name = input("Enter name: ")
            no = input("Enter number: ")
            hashtable.lininsert(name, no)
        elif choice == "2":
            name = input("Enter name: ")
            no = input("Enter number: ")
            hashtable.quadinsert(name, no)
        elif choice == "3":
            name = input("Enter name to search: ")
            hashtable.search(name)
        elif choice == "4":
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please choose again.")

if __name__ == "__main__":
    main()

