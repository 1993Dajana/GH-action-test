import requests
import numpy as np
import csv
from dateutil import parser

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
    # Example dateutil usage
    date_str = "2025-07-14T10:00:00Z"
    parsed_date = parser.isoparse(date_str)
    print(f"Parsed date: {parsed_date}")

if __name__ == "__main__":
    main()
