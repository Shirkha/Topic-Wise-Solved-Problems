Arranging the array
-- > You are given an array of size N. Rearrange the given array in - place such that all the negative numbers occur before positive numbers.(Maintain the order of all - ve and + ve numbers as given in the original array).

=>
// Inserttion sort concept    TC = O(N^2) SC = O(1)
int key, j;
for (int i = 1; i < n; i++) {
  key = arr[i];

  if (key > 0)
    continue;

  j = i - 1;
  while (j >= 0 and arr[j] > 0) {
    arr[j + 1] = arr[j];    // shift +ve no to right one position
    j--;
  }
  arr[j + 1] = key;
}

// Using extra space    TC = O(N)  SC = O(N)

int temp[n];   //only store the negative elements
int j = 0;
for (int i = 0; i < n; i++)
  if (arr[i] < 0)
    temp[j++] = arr[i];

if (j == n or j == 0) // All elements negative or positive
  return;
for (int i = 0; i < n; i++)
  if (arr[i] >= 0)
    temp[j++] = arr[i];

for (int i = 0; i < n; i++)
  arr[i] = temp[i];

// Using merge sort conecpt