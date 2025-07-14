import requests
import numpy as np

def main():
    print("Running my Python script with dependencies!")
    response = requests.get("https://httpbin.org/get")
    print(f"Response from httpbin: {response.status_code}")
    arr = np.array([1, 2, 3])
    print(f"Numpy array: {arr}")

if __name__ == "__main__":
    main()
