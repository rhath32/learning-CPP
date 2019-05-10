/* This bit of code creates a 10x10 2d array and populates it as a multiplication table
*  It then prints the table in a half-descending triangle.
*/
#include <iostream>
#include <iomanip>

int main()
{
   // declare a 10x10 array for a multiplication table
   const int nNumRows = 10;
   const int nNumCols = 10;
   int nProducts[nNumRows][nNumCols] = {0}; // initialize all to 0
   std::cout << std::setw(5); 

   // calculate multiplication table
   for (int nRow=0; nRow<nNumRows; nRow++) 
      for (int nCol=0; nCol<nNumCols; nCol++)
         nProducts[nRow][nCol] = nRow * nCol; 

   // print the table
   for (int nRow=1; nRow<nNumRows; nRow++) {
      for (int nCol=1; nCol<nNumCols; nCol++)
        if(nCol <= nRow) 
          std::cout << nProducts[nRow][nCol] << std::setw(5);
      std::cout << "\n";
   }
}

/**
* Line 23 is the key for print the half triangle. The outer loop iterates through the rows.
* The inner loop iterates through all columns. 
* If the nCols index is < nRow, print out the value at [nRow][nCol]
* ex nRow = 3, nCols (1 --> 9): only print columns 1, 2, 3
*/

