import random

class RandNumGenerator:
    def __init__(self, range, cap):
        self.range = int(range)
        self.cap = int(cap)
        self.storage = []
    
    # Generate will generate random int number and append it into storage
    def Generate(self):
        c = self.cap
        while c != 0:
            self.storage.append(random.randint(0, self.range))
            c -= 1

    # Show will 
    def Show(self):
        if self.storage:
            print("="*25 + "Show num" + "="*25)
            for num in self.storage:
                print(str(num) + " ")
            print("="*50)
        else:
            print("You don't generate number yet.")

    def Save(self):
        print("Saving...")
        text = ""
        for num in self.storage:
            text += str(num) + " "
        
        save_place = "./randnumRange%dCap%d.txt" % (self.range, self.cap)
        try:        
            with open(save_place, "w+") as file:
                file.write(text)
        except:
            print("Some error occur when saving file.")
        else:
            print("Successfully save file to %s" % save_place)

range = input("Input a range: \n")
cap = input("Input a num about how many randnum you want to generate.\n")
r = RandNumGenerator(range, cap)
r.Generate()

show = input("Generated. Do you want to show those number?[y/N]")
if show.lower() == "y":
    r.Show()
elif show.lower() == "n":
    pass
else:
    print("Invalid input!")

r.Save()
