import requests
import numpy as np
import csv

def main():
    print("Running my Python script with dependencies! Some modification.")
    response = requests.get("https://httpbin.org/get")
    print(f"Response from httpbin: {response.status_code}")
    arr = np.array([1, 2, 3])
    print(f"Numpy array: {arr}")
    print("Read data.csv")
    with open('data.csv', 'r') as file:
        for i, r in enumerate(csv.reader(file)):
            if i == 0:
                continue
            print(r)
        
if __name__ == "__main__":
    main()
