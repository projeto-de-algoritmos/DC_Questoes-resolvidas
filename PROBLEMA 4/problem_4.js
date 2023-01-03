/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    
    let i = 0, j = 0;
    let mergedArray = [];

    while(i < nums1.length && j < nums2.length) {
        if(nums1[i] >= nums2[j] && nums2[j] != null) {
            mergedArray.push(nums2[j]);
            j++;
        }
        if(nums1[i] < nums2[j] && nums1[i] != null) {
            mergedArray.push(nums1[i]);
            i++;
        }
    }

    while(nums1.length > i) {
        mergedArray.push(nums1[i]);
        i++;
    }

    while(nums2.length > j) {
        mergedArray.push(nums2[j]);
        j++;
    }

    let size = mergedArray.length;
    let meio = Math.floor(size/2);
    let mediana;
    if(size%2 === 0) {
        mediana = (mergedArray[meio] + mergedArray[meio-1])/2;  
    } else {
        mediana = mergedArray[meio];
    }

    return mediana
};