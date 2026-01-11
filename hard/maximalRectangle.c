// Maximal Rectangle


typedef signed int SI4;
typedef unsigned int UI4;

#define MASTER_MAX( value1, value2 ) (((value1) > (value2)) ? (value1) : (value2))
#define MASTER_IMAX( value1, value2 ) (value1) = MASTER_MAX(value1, value2)

/* #! 84. Largest Rectangle in Histogram - Modified !# */ UI4
MASTER_Algolib_LargestRectangleArea( const UI4 * const heights, const UI4 heightsSize ) {
    UI4 mstack[201];
    UI4 maxArea = 0;
    UI4 curHeight;
    UI4 popHeight;
    UI4 width;
    UI4 mstack_pos = 0;
    UI4 index = 0;
    for (; index < heightsSize; index += 1) {
        curHeight = heights[index];
        while (mstack_pos > 0 && heights[mstack[mstack_pos - 1]] > curHeight) {
			mstack_pos -= 1;
            popHeight = heights[mstack[mstack_pos]];
            width = (mstack_pos == 0) ? (index) : (index - mstack[mstack_pos - 1] - 1);
            MASTER_IMAX(maxArea, width * popHeight);
			mstack[mstack_pos] = 0;
		}
		mstack[mstack_pos] = index;
		mstack_pos += 1;
    }
    return maxArea;
}

#include <stdlib.h>
#include <string.h>

UI4
maximalRectangle( char** matrix, const UI4 matrixSize, const UI4 * const matrixColSize ) {
    const UI4 columns = matrixColSize[0];
    UI4 index = 0;
    UI4 jndex;
    UI4 maxArea = 0;
    UI4 newArea;
    UI4 heights[201];
    for (; index < matrixSize; index += 1) {
        for (jndex = 0; jndex < columns; jndex += 1)
            heights[jndex] = (matrix[index][jndex] == '1') ? (heights[jndex] + 1) : (0);
        newArea = MASTER_Algolib_LargestRectangleArea(heights, columns + 1);
        MASTER_IMAX(maxArea, newArea);
    }
    return maxArea;
}