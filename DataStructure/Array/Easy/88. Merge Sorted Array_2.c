

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if (0 == n) {
		return;
	}

	if (0 == m) {
		for (int i = 0; i < n; i++) {
			nums1[i] = nums2[i];
		}

		return;
	}

	int i = 0, j = 0;

	while (i < m && j < n) {
		if (nums1[i] > nums2[j]) {
			int temp = nums1[i];
			nums1[i] = nums2[j];
			nums2[j] = temp;
		}

		i++;
	}

	while(j < n) {
		nums1[i++] = nums2[j++];
	}
}