from testing import sorting_scaling_tests
from testing import sorting_assignments_tests
from testing import sorting_comparisons_tests
from testing import contents_check
from testing import stability_check
from mylist import mylist
from myint import myint

from examinationA import mergesort
from examinationA import insertionsort
from examinationA import selectionsort
from examinationA import binary_search

def mergesort_tests():
	num_tests = 9
	to_return = num_tests
	algorithm_name = 'Mergesort'
	print('----------')
	print('Starting {0} tests:'.format(algorithm_name))

	# Do all element remain?
	print()
	print('Checking if all elements are the original elements...', end='')
	old_to_return = to_return
	to_return += contents_check(mergesort, algorithm_name)
	if old_to_return == to_return:
		print('OK!')

	# Stable
	print()
	print('Checking if the relative order of elements are preserved...', end='')
	old_to_return = to_return
	to_return += stability_check(mergesort, algorithm_name)
	if old_to_return == to_return:
		print('OK!')

	# Assignments
	print()
	print('Performing sortorder and number of assignment tests... ', end='')
	old_to_return = to_return
	to_return += sorting_assignments_tests(mergesort, algorithm_name, [9,7,5,3,1,8,6,4,2,0], 68, 80)
	to_return += sorting_assignments_tests(mergesort, algorithm_name, [0,1,2,3,4,5,6,7,8,9], 68, 80)
	if old_to_return == to_return:
		print('OK!')

	# Comparisons
	print()
	print('Performing number of comparisons tests... ', end='')
	old_to_return = to_return
	to_return += sorting_comparisons_tests(mergesort, algorithm_name, [x for x in range(10)], 19, 40)
	to_return += sorting_comparisons_tests(mergesort, algorithm_name, [x for x in range(9, -1, -1)], 15, 40)
	if old_to_return == to_return:
		print('OK!')

	# Scaling
	scale_dict = {'random': 'linearithmic', 'sorted': 'linearithmic', 'reverse': 'linearithmic'}
	print()
	print('Performing time complexity tests...', end='')
	old_to_return = to_return
	to_return += sorting_scaling_tests(mergesort, algorithm_name, scale_dict)
	if old_to_return == to_return:
		print('OK!')

	return to_return, num_tests

def selectionsort_tests():
	if selectionsort([1]) is not None:
		return -10, None
	num_tests = 8
	to_return = num_tests
	algorithm_name = 'Selectionsort'

	print('----------')
	print('Starting {0} tests:'.format(algorithm_name))

	# Do all element remain?
	print()
	print('Checking if all elements are the original elements...', end='')
	old_to_return = to_return
	to_return += contents_check(selectionsort, algorithm_name)
	if old_to_return == to_return:
		print('OK!')

	# Assignments
	print()
	print('Performing sortorder and number of assignment tests... ', end='')
	old_to_return = to_return
	to_return += sorting_assignments_tests(selectionsort, algorithm_name, [9,7,5,3,1,8,6,4,2,0], 18, 50)
	to_return += sorting_assignments_tests(selectionsort, algorithm_name, [0,1,2,3,4,5,6,7,8,9], 18, 50)
	if old_to_return == to_return:
		print('OK!')

	# Comparisons
	print()
	print('Performing number of comparisons tests... ', end='')
	old_to_return = to_return
	to_return += sorting_comparisons_tests(selectionsort, algorithm_name, [x for x in range(10)], 45, 90)
	to_return += sorting_comparisons_tests(selectionsort, algorithm_name, [x for x in range(9, -1, -1)], 45, 90)
	if old_to_return == to_return:
		print('OK!')

	# Scaling
	scale_dict = {'random': 'quadratic', 'sorted': 'quadratic', 'reverse': 'quadratic'}
	print()
	print('Performing time complexity tests...', end='')
	old_to_return = to_return
	to_return += sorting_scaling_tests(selectionsort, algorithm_name, scale_dict)
	if old_to_return == to_return:
		print('OK!')

	return to_return, num_tests

def insertionsort_tests():
	# Assignments
	if insertionsort([1]) is not None:
		return -10, None

	num_tests = 9
	to_return = num_tests
	algorithm_name = 'Insertionsort'
	print('----------')
	print('Starting {0} tests:'.format(algorithm_name))

	# Do all element remain?
	print()
	print('Checking if all elements are the original elements...', end='')
	old_to_return = to_return
	to_return += contents_check(insertionsort, algorithm_name)
	if old_to_return == to_return:
		print('OK!')

	# Stable
	print()
	print('Checking if the relative order of elements are preserved...', end='')
	old_to_return = to_return
	to_return += stability_check(insertionsort, algorithm_name)
	if old_to_return == to_return:
		print('OK!')

	# Assignments
	print()
	print('Performing sortorder and number of assignment tests... ', end='')
	old_to_return = to_return
	to_return += sorting_assignments_tests(insertionsort, algorithm_name, [9,7,5,3,1,8,6,4,2,0], 44, 70)
	to_return += sorting_assignments_tests(insertionsort, algorithm_name, [0,1,2,3,4,5,6,7,8,9], 9, 30)
	if old_to_return == to_return:
		print('OK!')

	# Comparisons
	print()
	print('Performing number of comparisons tests... ', end='')
	old_to_return = to_return
	to_return += sorting_comparisons_tests(insertionsort, algorithm_name, [x for x in range(10)], 9, 30)
	to_return += sorting_comparisons_tests(insertionsort, algorithm_name, [x for x in range(9, -1, -1)], 45, 70)
	if old_to_return == to_return:
		print('OK!')

	# Scaling
	scale_dict = {'random': 'quadratic', 'sorted': 'linear', 'reverse': 'quadratic'}
	print()
	print('Performing time complexity tests...', end='')
	old_to_return = to_return
	to_return += sorting_scaling_tests(insertionsort, algorithm_name, scale_dict)
	if old_to_return == to_return:
		print('OK!')

	return to_return, num_tests

def binary_search_tests():
	num_tests = 6
	to_return = num_tests
	print('----------')
	print('Starting binary search tests:')
	print('Performing various searches.')

	# Comparisons
	lst = [myint(x) for x in range(100)]
	# myint.total_num_comparisons = 0
	# correct_comparisons = [13, 18, 19]
	# i = binary_search(lst, lst[-1])
	# if i != len(lst)-1:
	# 	print('Your binary search does not return the correct index.')
	# 	print('Should return {0} but did return {1}'.format(len(lst)-1, i))
	# 	print('The list of elements searched was [0, 1, 2, ..., 97, 98, 99]')
	# 	to_return -= 1
	# if myint.total_num_comparisons not in correct_comparisons:
	# 	print('Your binary search does too many comparisons searching for {0} in [0, 1, 2, ..., 97, 98, 99].'.format(lst[-1]))
	# 	print('Should be {0} comparisons, but performed {1} comparisons.'.format(correct_comparisons, myint.total_num_comparisons))
	# 	to_return -= 1

	myint.total_num_comparisons = 0
	correct_comparisons = [1]
	i = binary_search(lst, lst[(len(lst)-1)//2])
	if i != (len(lst)-1)//2:
		print('Your binary search does not return the correct index.')
		print('Should return {0} but did return {1}'.format(len(lst)-1, i))
		print('The list of elements searched was [0, 1, 2, ..., 97, 98, 99]')
		to_return -= 1
	if myint.total_num_comparisons not in correct_comparisons:
		print('Your binary search does too many comparisons searching for {0} in [0, 1, 2, ..., 97, 98, 99].'.format(lst[(len(lst)-1)//2]))
		print('Should do {0} comparison, but performed {1} comparisons.'.format(correct_comparisons[0], myint.total_num_comparisons))
		to_return -= 1

	myint.total_num_comparisons = 0
	correct_comparisons = [6, 12, 18]
	i = binary_search(lst, myint(-1))
	if i != -1:
		print('Your binary search does not return the correct index.')
		print('Should return {0} but did return {1}'.format(len(lst)-1, i))
		print('The list of elements searched was [0, 1, 2, ..., 97, 98, 99]')
		to_return -= 1
	if myint.total_num_comparisons not in correct_comparisons:
		print('Your binary search does too many comparisons searching for {0} in [0, 1, 2, ..., 97, 98, 99].'.format(lst[(len(lst)-1)//2]))
		print('Should do {0} comparisons, but performed {1} comparisons.'.format(correct_comparisons, myint.total_num_comparisons))
		to_return -= 1

	myint.total_num_comparisons = 0
	correct_comparisons = [7, 14, 21]
	i = binary_search(lst, myint(101))
	if i != -1:
		print('Your binary search does not return the correct index.')
		print('Should return {0} but did return {1}'.format(len(lst)-1, i))
		print('The list of elements searched was [0, 1, 2, ..., 97, 98, 99]')
		to_return -= 1
	if myint.total_num_comparisons not in correct_comparisons:
		print('Your binary search does too many comparisons searching for {0} in [0, 1, 2, ..., 97, 98, 99].'.format(lst[(len(lst)-1)//2]))
		print('Should do {0} comparisons, but performed {1} comparisons.'.format(correct_comparisons, myint.total_num_comparisons))
		to_return -= 1

	# lst = [myint(x) for x in range(100)]+[myint(x) for x in range(110,200)]
	# correct_comparisons = [12, 16, 20]
	# myint.total_num_comparisons = 0
	# i = binary_search(lst, myint(105))
	# if i != -1:
	# 	print('Your binary search does not return the correct index.')
	# 	print('Should return {0} but did return {1}'.format(len(lst)-1, i))
	# 	print('The list of elements searched was [0, 1, 2, ..., 97, 98, 99]')
	# 	to_return -= 1
	# if myint.total_num_comparisons not in correct_comparisons:
	# 	print('Your binary search does too many comparisons searching for {0} in [0, 1, ..., 98, 99, 110, 111, ..., 199, 200].'.format(lst[(len(lst)-1)//2]))
	# 	print('Should do {0} comparisons, but performed {1} comparisons.'.format(correct_comparisons, myint.total_num_comparisons))
	# 	to_return -= 1



	return to_return, num_tests

def main():
	all_tests_passed = True
	num_total_tests = 0
	num_tests_passed = 0

	to_return = selectionsort_tests()
	if to_return[0] == -10:
		to_return = insertionsort_tests()
		if to_return[0] == -10:
			print('------')
			print('------')
			print('You have to implement either Insertionsort or Selectionsort, you cannot skip both.')
			print('Remember to remove the return at the bottom of the function of Selectionsort/Insertionsort.')
			print('------')
			print('------')
			num_total_tests += 10
		else:
			print('Passed {0}/{1} tests for Insertionsort.'.format(to_return[0], to_return[1]))
			num_total_tests += to_return[1]
			num_tests_passed += to_return[0]
			if to_return[0] != to_return[1]:
				all_tests_passed = False
	else:
		print('Passed {0}/{1} tests for Selectionsort.'.format(to_return[0], to_return[1]))
		num_total_tests += to_return[1]
		num_tests_passed += to_return[0]
		if to_return[0] != to_return[1]:
			all_tests_passed = False

	to_return = mergesort_tests()
	print('Passed {0}/{1} tests for Mergesort.'.format(to_return[0], to_return[1]))
	num_total_tests += to_return[1]
	num_tests_passed += to_return[0]
	if to_return[0] != to_return[1]:
		all_tests_passed = False

	to_return = binary_search_tests()
	print('Passed {0}/{1} tests for binary search'.format(to_return[0], to_return[1]))
	num_total_tests += to_return[1]
	num_tests_passed += to_return[0]
	if to_return[0] != to_return[1]:
		all_tests_passed = False

	if all_tests_passed is True:
		print('----------')
		print('All tests passed!')
	else:
		print('----------')
		print('Passed {0}/{1} tests in total.'.format(num_tests_passed, num_total_tests))

if __name__ == '__main__':
	main()