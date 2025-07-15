import os
import requests
import numpy as np

from dateutil import parser
from argparse import ArgumentParser

def parse_args():
    parser = ArgumentParser()
    parser.add_argument('-e', '--elf')
    return parser.parse_args()

def main(args):
    print("Running my Python script with dependencies! Some modification.")
    response = requests.get("https://httpbin.org/get")
    print(f"Response from httpbin: {response.status_code}")
    arr = np.array([1, 2, 3])
    print(f"Numpy array: {arr}")
    date_str = "2025-07-14T10:00:00Z"
    parsed_date = parser.isoparse(date_str)
    print(f"Parsed date: {parsed_date}")
    print(f"Elf: {args.elf}. Exists: {os.path.exists(args.elf)}")

if __name__ == "__main__":
    main(parse_args())
