from functions import add, delete, show, inc

def write(flights):
    for p in flights:
        print(p)

def console():
    print("\nwelcome to console\n")
    flights = [{"code": "2RFF2", "duration": 20, "dep_c": "Cluj-Napoca", "dest_c": "Landom"},
               {"code": "3D2E1", "duration": 30, "dep_c": "Bistrita", "dest_c": "Mures"},
               {"code": "3D234", "duration": 25, "dep_c": "Bistrita", "dest_c": "Zalau"},
               {"code": "33DE1", "duration": 30, "dep_c": "Bistrita", "dest_c": "Cluj-Napoca"},
               {"code": "3D2R1", "duration": 60, "dep_c": "Botosani", "dest_c": "Mures"}
               ]
    while True:
        try:
            command_line = input("Enter a command:").strip()
            parts = command_line.split(maxsplit=1)
            if not parts:
                continue
            command = parts[0]
            if len(parts) > 1:
                args = parts[1]
            else: args = ""
            if command == "help":
                print("Available commands:")
                print("add <code> <duration> <dep_c> <dest_c>")
                print("delete <code>")
                print("show by <dep_c>")
                print("increase duration from <dep_c> by <minutes>")
                print("exit")
                print()
                write(flights)
            elif command == "add":
                try:
                    code = args.split()[0]
                    duration = args.split()[1]
                    dep_c = args.split()[2]
                    dest_c = args.split()[3]
                    write(add(flights, code, duration, dep_c, dest_c))
                    #write(flights)
                except ValueError as ve:
                    print(ve)
            elif command == "delete":
                code = args.split()[0]
                write(delete(flights, code))
               # write(flights)
            elif command == "show":
                if args.startswith("by"):
                    dep_c = args.split()[1]
                    write(show(flights, dep_c))
                    #write(flights)
            elif command == "increase":
                if args.startswith("duration"):
                    try:
                        dep_c = args.split()[2]
                        minutes = int(args.split()[4])
                        write(inc(flights, dep_c, minutes))
                        #write(flights)
                    except ValueError as ve:
                        print(ve)
            elif command == "exit":
                break
            else:
                print("invalid command")
        except ValueError as ve:
            print(ve)


'''
def menu():
    print("\nWELCOME TO MENU\n")
    print("Chose a command:")
    print("1. Add a flight")
    print("2. Delete a flight")
    print("3. Show by a given departure")
    print("4. Increase duration")
    print("5. Exit")
    flights = [{"code":"2RFF2", "duration":20, "dep_c":"Cluj-Napoca", "dest_c":"Landom"},
               {"code":"3D2E1", "duration":30, "dep_c":"Bistrita", "dest_c":"Mures"},
               {"code":"3D234", "duration": 25, "dep_c": "Bistrita", "dest_c": "Zalau"},
               {"code":"33DE1", "duration":30, "dep_c":"Bistrita", "dest_c":"Cluj-Napoca"},
               {"code":"3D2R1", "duration":60, "dep_c":"Botosani", "dest_c":"Mures"}
               ]
    print()
    print("The given flights: ")
    write(flights)
    print()
    while True:
        try:
            choice = input("Enter your choice: ")
            if choice == "1":
                try:
                    code = input("Enter flight code: ")
                    duration = int(input("Enter duration: "))
                    dep_c = input("Enter departure city: ")
                    dest_c = input("Enter destination city: ")
                    flights = add(flights, code, duration, dep_c, dest_c)
                    write(flights)
                except ValueError as ve:
                    print(ve)
            if choice == "2":
                 code = input("Enter flight code: ")
                 flights = delete(flights, code)
                 write(flights)
            elif choice == "3":
                dep_c = input("Enter flight departure: ")
                flights = show(flights, dep_c)
                write(flights)
            elif choice == "4":
                dep_c = input("Enter flight departure: ")
                minutes = int(input("Enter the minutes: "))
                flights = inc(flights, dep_c, minutes)
                write(flights)
            elif choice == "5":
                break
        except ValueError as ve:
            print(f"Error: {ve}")
'''

def main():
    'menu()'
    console()

if __name__ == "__main__":
    main()

