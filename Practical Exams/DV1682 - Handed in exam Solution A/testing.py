from mylist import mylist
from myint import myint
from time import perf_counter
from random import randint

INCREASE_OF_NUMBERS = 10;
LINEAR_LOWER = 3;
LINEAR_UPPER = 20;
LINEARITHMIC_LOWER = 8;
LINEARITHMIC_UPPER = 40;
QUADRATIC_LOWER = 40;
QUADRATIC_UPPER = 200;

def contents_check(algorithm, algorithm_name):
	num_elements = 10
	elementsA = [myint(x%5, x//5) for x in range(num_elements)]
	elementsB = [elementsA[x] for x in range(num_elements)]

	algorithm(elementsA);
	count = 0;
	for i in range(num_elements):
		for j in range(num_elements):
			if elementsA[i] == elementsB[j] and elementsA[i].control == elementsB[j].control:
				count += 1
	if count != num_elements:
		print("Your sorted array does not contain the same elements as before. Do not remove or alter elements in your algorithm.")
		return -1
	return 0

def stability_check(algorithm, algorithm_name):
	num_elements = 11
	elements = [myint(1,1),
				myint(9,1), 
				myint(7,1),
				myint(5,1),
				myint(1,2),
				myint(7,2),
				myint(9,2),
				myint(7,3),
				myint(5,2),
				myint(5,3),
				myint(1,3)]
	elements_copy = [myint(1,1), 
					myint(9,1), 
					myint(7,1),
					myint(5,1),
					myint(1,2),
					myint(7,2),
					myint(9,2),
					myint(7,3),
					myint(5,2),
					myint(5,3),
					myint(1,3)]

	algorithm(elements)
	check_stable = True
	for i in range(num_elements-1):
		if not(elements[i] < elements[i+1] or (elements[i] == elements[i+1] and elements[i].control < elements[i+1].control)):
			check_stable = False

	if not check_stable:
		print()
		print('Your {0} does not preserve the relative order of elements -> It is not a stable sorting implementation.'.format(algorithm_name))
		return -1

	num_elements = 10
	elements = elements[:num_elements]
	for i in range(num_elements):
		elements[i] = elements_copy[i];

	algorithm(elements);	# Testing on 10 elements also.
	check_stable = True
	for i in range(num_elements-1):
		if not(elements[i] < elements[i+1] or (elements[i] == elements[i+1] and elements[i].control < elements[i+1].control)):
			check_stable = False

	if not check_stable:
		print()
		print('Your {0} does not preserve the relative order of elements -> It is not a stable sorting implementation.'.format(algorithm_name))
		return -1

	return 0

def sorting_scaling_tests(algorithm, algorithm_name, scaling, num_elements=100, num_range=1000):
	'''
		Performs scaling tests on random, sorted, and sorted reverse data with dataset size num_elements to 10*times num_elements.
		The scaling parameter should indicate how the algorithm scales on random, sorted, and sorted reverse.
		The num_range parameter decides the range for the random number generation, i.e. [0, num_range]

	'''
	# Random data
	if scaling['random'] is not None:
		to_return = 0
		lst_a = [randint(0, num_range) for x in range(num_elements)]
		lst_b = [randint(0, num_range) for x in range(num_elements*INCREASE_OF_NUMBERS)]
		to_return += sorting_scaling_test(algorithm, scaling['random'], lst_a, lst_b, algorithm_name, 'random')
	# Sorted data
	if scaling['sorted'] is not None:
		lst_a = sorted([randint(0, num_range) for x in range(num_elements)])
		lst_b = sorted([randint(0, num_range) for x in range(num_elements*INCREASE_OF_NUMBERS)])
		to_return += sorting_scaling_test(algorithm, scaling['sorted'], lst_a, lst_b, algorithm_name, 'sorted')
	# Sorted reverse data
	if scaling['reverse'] is not None:
		lst_a = sorted([randint(0, num_range) for x in range(num_elements)], reverse=True)
		lst_b = sorted([randint(0, num_range) for x in range(num_elements*INCREASE_OF_NUMBERS)], reverse=True)
		to_return += sorting_scaling_test(algorithm, scaling['reverse'], lst_a, lst_b, algorithm_name, 'sorted reverse')

	return to_return

def sorting_scaling_test(algorithm, scaling, lst_a, lst_b, algorithm_name, data_type):
	lower, upper = LINEAR_LOWER, LINEAR_UPPER
	if scaling == 'linearithmic':
		lower, upper = LINEARITHMIC_LOWER, LINEARITHMIC_UPPER
	elif scaling == 'quadratic':
		lower, upper = QUADRATIC_LOWER, QUADRATIC_UPPER

	start_a = perf_counter()
	algorithm(lst_a)
	stop_a = perf_counter()
	start_b = perf_counter()
	algorithm(lst_b)
	stop_b = perf_counter()

	if not lower <= (stop_b - start_b)/(stop_a - start_a) <= upper:
		print('{0} does not sort according to its time complexity on {1} data.'.format(algorithm_name, data_type))
		if (stop_b - start_b)/(stop_a - start_a) > upper:
			print('It sorts too slow.')
		else:
			print('It sorts too fast.')
		print()
		return -1
	return 0

def sorting_assignments_tests(algorithm, algorithm_name, data, optimal_num_assignments, max_num_assignments=-1):
	'''
		Performs tests on number of assignments used within the sorting algorithm. Requires both the data and
		the number of assignments that the algorithm is supposed to do on that data.
	'''
	lst = mylist()
	for val in data:
		lst.append(val)
	sorted_lst = mylist(sorted(data))

	mylist.total_num_assignments = 0
	algorithm(lst)
	if sorted_lst != lst:
		print('{0} did not sort {1} correctly.'.format(algorithm_name, data))
		print('Your list looks like: ',lst)
		print()
		return -1
	if mylist.total_num_assignments != optimal_num_assignments:
		if max_num_assignments != -1 and mylist.total_num_assignments <= max_num_assignments:
			print('{0} does not assign the optimal amount of elements, but is OK.'.format(algorithm_name))
		else:	
			print('{0} does not assign elements as defined in the algorithm description.'.format(algorithm_name))
			print('Your algorithm did {0} assignments. It should do {1} assignments.'.format(mylist.total_num_assignments, optimal_num_assignments))
			print()
			return -1
	return 0

def sorting_comparisons_tests(algorithm, algorithm_name, data, optimal_num_comparisons, max_num_comparisons=-1):
	'''
		Performs tests on number of comparisons (i.e. < ) used within the sorting algorithm. Requires both the data and
		the number of comparisons that the algorithm is supposed to do on that data.
	'''
	data = [myint(x) for x in data]
	myint.total_num_comparisons = 0
	algorithm(data)
	if isinstance(optimal_num_comparisons, list):
		if myint.total_num_comparisons not in optimal_num_comparisons:
			print('{0} performs too many comparisons on the data {1}. Follow the algorithms definition.'.format(algorithm_name, data))
			print('Your algorithm did {0}. It should do {1}.'.format(myint.total_num_comparisons, optimal_num_comparisons))
			return -1
	else:
		if myint.total_num_comparisons != optimal_num_comparisons:
			if max_num_comparisons == -1 or myint.total_num_comparisons > max_num_comparisons:
				print('{0} performs too many comparisons on the data {1}. Follow the algorithms definition.'.format(algorithm_name, data))
				print('Your algorithm did {0}. It should do {1}'.format(myint.total_num_comparisons, optimal_num_comparisons), end='')
				if max_num_comparisons != -1: 
					print(', but at most {0}.'.format(max_num_comparisons))
				else:
					print('.')
				return -1
			elif myint.total_num_comparisons <= max_num_comparisons:
				print('{0} does not compare the optimal amount of elements, but is OK.'.format(algorithm_name))

	return 0