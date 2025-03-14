function LinearSearch(pArr, nKey) {
    for (var i = 0; i < pArr.length; i++) {
        if (nKey == pArr[i]) {
            return i;
        }
    }
    return -1;
}

var arr = [23, 47, 19, 63, 57, 26, 75, 73, 82, 89, 47, 11];
var key = 75;

var idx = LinearSearch(arr, key);

if (idx == -1) {
    console.log("Key not found in the array");
} else {
    console.log("Key found at index: " + (idx + 1) );
}