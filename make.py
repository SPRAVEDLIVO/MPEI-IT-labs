import os, re

d = r"C:\Users\SPRAVEDLIVO\source\repos\Project1\Project1"

search = re.compile(r"(.*)_(.*)")

file = input("Enter lab name: ")
found = list(search.findall(file)[0])
found[1] += ".cpp"

for f in os.listdir(d):
    if os.path.splitext(f)[1] == ".cpp":
        with open(os.path.join(d, f), encoding="utf_8_sig") as f:
            if not os.path.exists(found[0]):
                os.makedirs(found[0])
            with open(os.path.join(found[0], "_".join(found)), "w", encoding="utf_8_sig") as fw:
                fw.write(f.read())

print("Work done! Saved another 30 seconds.")