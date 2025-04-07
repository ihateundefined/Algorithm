//선택정렬
function selectionSort(arr)
{
    var len = arr.length;
    var minidx = 0;

    for(var i = 0; i < len - 1; i++){
        for(var j = 1 + i, minidx = i; j < len; j++){
            if(arr[minidx] > arr[j]){
               minidx = j;
            }
        }
        if(minidx != i){
            var temp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = temp;
        }
    }
    return arr;
}

var unsortedArray = [64, 34, 25, 12, 22, 11, 90];
console.log("정렬 전 : ", unsortedArray);
//선택 정렬
var sortedArray = selectionSort(unsortedArray);

console.log("정렬 후 : ", sortedArray);