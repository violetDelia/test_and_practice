bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int col = matrixColSize[0];
    int row = matrixSize;
    int begin = 0;
    int end = col * row - 1;
    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2;
        if (target > matrix[mid / col][mid % col])
        {
            begin = mid + 1;
        }
        else if (target < matrix[mid / col][mid % col])
        {
            end = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

