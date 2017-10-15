"""
Problem: UVa 10815 - Andy's First Dictionary
Approach: Python
"""
from sys import stdin
from re import split

text = stdin.read()
text = text.strip().lower()
words = set(split(r'[^a-z]', text))

for word in sorted(words):
    if(word):
        print(word)
