from myint import myint

class mylist():
	total_num_assignments = 0
	"""
	Overload of conventional list to count number of assignments done to the list
	"""
	#def __init__(self):
	#	self.num_assignments = 0
	def __init__(self, start=[]):
		self.wrapped = []                        # Make sure it's a list here.
		self.num_assignments = 0
		for x in start:
			self.wrapped.append(x)
			mylist.total_num_assignments += 1
			self.num_assignments += 1
	
	def __setitem__(self, index, value):
		if isinstance(index, int):
			self.num_assignments += 1
			mylist.total_num_assignments += 1
			self.wrapped[index] = value
		elif isinstance(index, slice):
			if len(value) != (index.stop - index.start):
				raise IndexError('Slice does not match length of values.')
			i = 0
			for ind in range(index.start, index.stop):
				self.wrapped[ind] = value[i]
				i+=1
				mylist.total_num_assignments += 1
		elif isinstance(index, myint):
			self.num_assignments += 1
			mylist.total_num_assignments += 1
			self.wrapped[int(index)] = value
		else:
			for i in index:
				self.wrapped[i] = value
				mylist.total_num_assignments += 1
		#print('in setitem')
	
	def __add__(self, other):
		return mylist(self.wrapped + other)

	def __mul__(self, time):
		return mylist(self.wrapped * time)

	def __getitem__(self, key):
		if isinstance(key, slice):
			start, stop, step = key.start, key.stop, key.step
			if start is None:
				start = 0
			if stop is None:
				stop = len(self.wrapped)
			if step is None:
				step = 1

			sliced_data = self.wrapped[start:stop:step]
			return mylist(sliced_data)
		return self.wrapped[key]

	def __len__(self):
		return len(self.wrapped)

	def __getslice__(self, low, high):
		#mylist.total_num_assignments += (high-low)
		return mylist(self.wrapped[low:high])

	def append(self, node):
		self.wrapped.append(node)

	def __getattr__(self, name):                 # Other members: sort/reverse/etc
		return getattr(self.wrapped, name)

	def __repr__(self):
		return '['+', '.join(map(str,self.wrapped))+']'

	def __str__(self):
		return '['+', '.join(map(str,self.wrapped))+']'

	def clear_assignments(self):
		self.num_assignments = 0

	def __iter__(self):
		self.idx = 0
		return self

	def __next__(self):
		self.idx += 1
		try:
			return self.wrapped[self.idx-1]
		except IndexError:
			self.idx = 0
			raise StopIteration

	def __eq__(self, other):
		return self.wrapped == other.wrapped

	def __lt__(self, other):
		return self.wrapped < other.wrapped

	def __gt__(self, other):
		return self.wrapped > other.wrapped

	def __le__(self, other):
		return self.wrapped <= other.wrapped

	def __ge__(self, other):
		return self.wrapped >= other.wrapped

	def __ne__(self, other):
		return self.wrapped != other.wrapped

def main():
	a = mylist()

	a.append(0)
	a.append(1)
	a.append(0)
	a.append(1)
	a.append(0)
	a.append(1)
	a.append(0)
	a.append(1)

	print(a)
	a[0] = 1
	a[1] = 0
	print(a.num_assignments)
	print(a)

	a[0],a[1] = a[1],a[0]
	print(a.num_assignments)
	print(a)

	a[2:4] = [9,7]
	print(a)

if __name__ == '__main__':
	main()