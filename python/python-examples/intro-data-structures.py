# list can have any type data inside of it they are dynamic arrays
# Order matters when comparing to lists [1, 2] == [1, 2]
# but [1, 2] does not = [2, 1]

my_list = [True, 3, "jarron", 10]
print("Length = %d" % len(my_list))

# set is the same as a list but can not have duplicate values
# if there is duplicate values it will represent a length of 1
# Order does not matter when comparing values
my_set = {1, 1, 3, 55}
print("Length = %d" % len(my_set))

# tuples are static arrays that are immutable and can not change
# values can not be changed but the items it may hold may be change
my_tuple = (1, 3, my_list)
print(my_tuple)
my_list.append(3)
print(my_tuple)

