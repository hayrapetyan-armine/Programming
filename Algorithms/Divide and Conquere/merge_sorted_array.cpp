void merge(vector<int>& nums1, vector<int>& nums2) {
    
    int len1 = nums1.size(), len2 = nums2.size(), index1, index2;

    if (len1 == 1 && nums1[0] == 0) {
        nums1[0] = nums2[0];
        return;
    }
    
    index1 = len1 - len2 - 1;
    index2 = len2 - 1;

    int i = len1 - 1;

        while (index1 >= 0  && index2 >= 0) {
            if (nums1[index1] < nums2[index2]) {
                nums1[i] = nums2[index2];
                index2--;
            } else {
                int temp = nums1[index1];
                nums1[index1] = nums1[i];
                nums1[i] = temp;
                index1--;
            }
            i--;
        }
    for (i = index2; i >= 0; i--) {
        nums1[i] = nums2[i];  
    }
}
