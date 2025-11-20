#/usr/bin/python3

# The equation of time is 
# t = 1 / f
# s = 1 / hz --> seconds = 1 / hertz 
# so by default the delay is 0.0625 

class Clock:
	
	def __init__(self, frequency: int = 16000000) -> None:
		self.frequency = frequency

	def get_frequency(self) -> int:
		return self.frequency
	
	def get_time(self) -> int:
		return 1 / self.frequency
