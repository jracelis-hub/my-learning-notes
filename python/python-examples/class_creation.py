# Built in error handling
# ValueError
# TypeError
# NameError
# ZeroDivisionError

# Raises an error think of fprintf(stderr)


class Recipe:
	"""
	Recipe is an object that holds the name and 
	and a dictionary of ingredients
	"""

	def __init__(self, cuisine: str = "Unknown", name: str = "Unknown") -> None:
		"""
		self.name = the name of the recipe
		self.cuisine = the type of recipe that it is
		self.ingredients = dictionary of ingredients in a the recipe
		self.instructions = list of strings of how to create the recipe
		"""
		self.name = name
		self.cuisine = cuisine
		self.ingredients = {}
		self.instruction = []
	
	def add_ingredient(self, ingredient: str, measurement: str) -> None:
		if type(measurement) is not str:
			raise ValueError(f"{measurement} needs to be a string")
		self.ingredients[ingredient] = measurement

	def get_measurement(self, ingredient):
		print(f'{self.ingredients[ingredient]}')

class Cruisine:

	def __init__(self):
		pass
	

# Use raise to just let the user know that it is invalid
class Poultry:
	poultry = {"meat", "seafood", "fish"}

	def __init__(self, poultry_type: str) -> None:
			# Checks if the input is within 
			if poultry_type not in self.poultry:
				raise ValueError(f"{poultry_type} is not a valid poultry type.")
			self.poultry = poultry_type 
	
