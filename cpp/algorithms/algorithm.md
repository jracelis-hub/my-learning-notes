# Algorithms

Bubble Sort - loops through the array n^2 times to swap lowest values to the left and high values to the right
- Upon each loop the last element will always be sorted (highest or lowest) depending on type
- algo looks like 
```
for (int i = 0; i < size_array; i++) {
	for (int j = 0; j < size_array - 1 - i; j++) {
		if (array[j] < array[j+1]) {
			swap(array[j], array[j+1]
		}
	}
}
```

Merge Sort - breaks the array down into halves until the array only contains itself. Once the array is just one value
merging occurs comparing left value to right value and working its way back up.

Quick Sort - choose a pivot in the array and seperate lowest values on the left side and the highest values on the right side.
When right side exceeds left side swap the pivot in that location

Selection Sort - look for minimum value and swap it to the first index keep doing this until 
```
int minimum = array[0];
for (int i = 0; i < size_array - 1; i++) {
	minimum = array[i];
	for (int j = i; j < size_array - 1; j++) {
		if (array[j] < minimum) {
			/* Checks if array[j] is */
			minimum = array[j];
		}
	}
	/* Swap the most update min with the first element */
	swap(minimum, array[i]);
}
```

Insertion Sort - looks at the first element in the array 
```
int j;
for (int i = 1; i < size; i++)
{
	j = i
	while (j > 0 && array[j-1] > a[j])
	{
		swap(array[j], array[j-1])
		j--;
	}
}
```

