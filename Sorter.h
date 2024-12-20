#pragma once



#include<vector>
using std::vector;



// DEC.

class clsSorter final {

	public:

		enum enOrder {
			ASC = 1 , DESC = 2
		};

		template <typename T>
		static void bubbleSort(vector<T>&,enOrder);

		template <typename T>
		static void selectionSort(vector<T>&,enOrder);

		template <typename T>
		static void insertionSort(vector<T>&, enOrder);

		template <typename T>
		static void mergeSort(vector<T>&,int,int,enOrder);


	private:

	template<typename T>
	static void merge(vector<T>&,int,int,int,enOrder);

	template<typename T>
	static void selectionSortASC(vector<T>&);

	template<typename T>
	static void selectionSortDESC(vector<T>&);

};


// DEF.



template<typename T>
void clsSorter::bubbleSort(vector<T>& vNums, enOrder order) {

	// Time Complexity: O(n^2)
	// Bubble sort let's smaller elements bubble at the top (beggining) of the list while small elements sink to the bottom.

	const int size = vNums.size();

	if (size == 0) {
		cout << "Empty List !";
		return;
	}

	for (int i = 0; i < size - 1 ; i++) {

		for (int j = 0; j < size - i - 1; j++) {

			if (order == enOrder::ASC) {
				if (vNums[j] > vNums[j + 1]) {
					T temp = vNums[j];
					vNums[j] = vNums[j + 1];
					vNums[j + 1] = temp;
				}
			}
			else {
				if (vNums[j] < vNums[j + 1]) {
					T temp = vNums[j];
					vNums[j] = vNums[j + 1];
					vNums[j + 1] = temp;
				}
			}
		}
	}


}







template<typename T>
void clsSorter::selectionSort(vector<T>& vNums, enOrder order) {

	// Time Complexity: O(n^2)
	// Selection Sort algorithm is a greedy algorithm that works by choosing the min/max element at each iteration and putting it at the start/end of the list.
	
	const int size = vNums.size();

	if (size == 0) {
		cout << "Empty List !";
		return;
	}

	 (order == enOrder::ASC) ? clsSorter::selectionSortASC<T>(vNums) : clsSorter::selectionSortDESC<T>(vNums);
		
}

template<typename T>
void clsSorter::selectionSortASC(vector<T>& vNums) {

	const int size = vNums.size();

	for (int i = 0; i < size; i++) {

		int minIndex = i;

		for (int j = i; j < size; j++) {
			if (vNums[j] < vNums[minIndex]) {
				minIndex = j;					
			}
		}

		T temp = vNums[minIndex];
		vNums[minIndex] = vNums[i];
		vNums[i] = temp;
	}


}

template<typename T>
void clsSorter::selectionSortDESC(vector<T>& vNums) {

	const int size = vNums.size();

	for (int i = 0; i < size; i++) {

		int maxIndex = i;

		for (int j = i; j < size; j++) {
			if (vNums[j] > vNums[maxIndex]) {
				maxIndex = j;
			}
		}

		T temp = vNums[maxIndex];
		vNums[maxIndex] = vNums[i];
		vNums[i] = temp;
	}


}




template<typename T>
void clsSorter::insertionSort(vector<T>& vNums, enOrder order) {

	const int size = vNums.size();

	if (size == 0) {
		cout << "Empty List";
		return;
	}


	for (int i = 1; i < size; i++) {

		int key = vNums[i];
		int j = i - 1;

		if (order == enOrder::DESC) {
			while (j >= 0 && vNums[j] < key) {
				vNums[j + 1] = vNums[j];
				j = j - 1;
			}
		}
		else {
			while (j >= 0 && vNums[j] > key) {
				vNums[j + 1] = vNums[j];
				j = j - 1;
			}
		}



		vNums[j + 1] = key;
	}


}






template <typename T>
void clsSorter::mergeSort(vector<T> &vNums , int start , int end , enOrder order) {

	const int size = vNums.size();

	if (size == 0) {
		cout << "Empty List";
		return;
	}

	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	clsSorter::mergeSort(vNums,start,mid,order);
	clsSorter::mergeSort(vNums,mid+1,end,order);

	clsSorter::merge(vNums,start,mid,end,order);

}


template <typename T>
void clsSorter::merge(vector<T>& vNums, int start, int mid, int end, enOrder order) {

	int leftArraySize = mid - start + 1;
	int rightArraySize = end - mid;

	vector<T> vLeft(leftArraySize,0);
	vector<T> vRight(rightArraySize,0);


	for (int i = 0; i < leftArraySize; i++) {
		vLeft[i] = vNums[start + i];
	}

	for (int i = 0; i < rightArraySize; i++) {
		vRight[i] = vNums[mid + i + 1];
	}


	int i = 0;
	int j = 0;
	int k = start;

	while (i < leftArraySize && j < rightArraySize) {

		if (order == enOrder::DESC) {

			if (vLeft[i] >= vRight[j]) {

				vNums[k] = vLeft[i];
				i++;

			}
			else {
				vNums[k] = vRight[j];
				j++;
			}

			

		}
		else {


			if (vLeft[i] <= vRight[j]) {
				vNums[k] = vLeft[i];
				i++;
			}
			else {
				vNums[k] = vRight[j];
				j++;
			}


		}



		k++;
	}



	while (i < leftArraySize) {
		vNums[k] = vLeft[i];
		i++;
		k++;
	}


	while (j < rightArraySize) {
		vNums[k] = vRight[j];
		j++;
		k++;
	}


}






