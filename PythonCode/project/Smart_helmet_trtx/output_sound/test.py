import threading
import sound_single as outsd

l = []

for i in range(5):
    if(not l):
        t = threading.Thread(target = outsd.Play_Sound(), args = [])
        l.append(t)

print(l)
for i in l:
    i.start()
    print(i)

for i in l:
    i.join()
