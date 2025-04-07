function bubbleSort(arr)
{
    var len = arr.length;

    for (var i = 0; i < len - 1; i++)
    {
        for (var j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                var temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

var unsortedArray = [5, 3, 8, 4, 2];
console.log("정렬 전 : ", unsortedArray);

// 버블 정렬
var sortedArray = bubbleSort(unsortedArray);
console.log("정렬 후 : ", sortedArray);