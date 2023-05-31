import sys, os

tiedosto = sys.argv[1]

os.system(f"g++ -std=c++11 {tiedosto} -o {tiedosto[:-4]} -O2")
os.system(f"{tiedosto[:-4]}.exe")
