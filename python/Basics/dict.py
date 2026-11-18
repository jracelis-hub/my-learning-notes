# Dict is a key value pair that takes an iterable as an argument when using a constructor

myDict: dict = dict({1: "value", 2: "key"})
Dict:dict = dict(key="value")

# Or this
dictionary: dict = {1: "another", 2: "way"}

print(myDict)
print(Dict)
print(dictionary)

# To get a specific value this takes a key as an argument 
print(Dict.get("key"))

# This copies all the content of Dict into another object another
another: dict = Dict.copy()
print(another)
