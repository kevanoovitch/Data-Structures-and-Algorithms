#from sorting import insertionsort

class myint():
	total_num_comparisons = 0

	def __init__(self, x=0, control=0):
		self.x = x
		self.control = control

	# Comparisons

	def __lt__(self, other):
		myint.total_num_comparisons += 1
		return self.x < other.x

	def __gt__(self, other):
		myint.total_num_comparisons += 1
		return self.x > other.x

	def __le__(self, other):
		myint.total_num_comparisons += 1
		return self.x <= other.x

	def __ge__(self, other):
		myint.total_num_comparisons += 1
		return self.x >= other.x

	def __eq__(self, other):
		myint.total_num_comparisons += 1
		return self.x == other.x

	# Binary ones

	def __add__(self, other):
		if isinstance(other, self.__class__):
			return self.x + other.x
		elif isinstance(other, int):
			return self.x + other
		else:
			raise TypeError("unsupported operand type(s) for +: '{}' and '{}'").format(self.__class__, type(other))

	def __mod__(self, other):
		if isinstance(other, self.__class__):
			return self.x % other.x
		elif isinstance(other, int):
			return self.x % other
		else:
			raise TypeError("unsupported operand type(s) for +: '{}' and '{}'").format(self.__class__, type(other))

	def __repr__(self):
		return str(self.x)

	def __str__(self):
		return str(self.x)

	# magic method to handle casting to int
	def __int__(self):
		return self.x

	# Allows us to use myint as indexes
	def __index__(self):
		return self.x

	def reset_comparisons(self):
		myint.total_num_comparisons = 0

def main():

	a = [myint(x) for x in range(1000,-1,-1)]
	insertionsort(a)
	print(myint.total_num_comparisons)
	myint.total_num_comparisons = 0
	insertionsort(a)
	print(myint.total_num_comparisons)
	

if __name__ == '__main__':
	main()