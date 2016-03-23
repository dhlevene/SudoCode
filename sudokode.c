// Daniel Levene, da935603, sudokode.c

#include <stdio.h>
#include <stdlib.h>

int arraytemp[9];

int main(void){

int i, j, k, l, m, n, numgrids, rowcheck, colscheck, noncheck;
int rowcount = 0, colscount = 0, noncount = 0;
int grid[9][9];

    //Number of grids that will be tested
    scanf("%d", &numgrids);
        for(n=0; n<numgrids; n++){
            for (i=0; i<9; i++){
                for(j=0;j<9;j++){
                    scanf("%d", &grid[i][j]); //scanning puzzle into 2d array
                            }
                        }
//Rows
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
       arraytemp[j] = grid[i][j]; //scanning in each row to a temporary array for checking
        }
    rowcheck = checkarray(); //calling checkarray method
        if(rowcheck == 1) //if method comes back true, row is unique
            rowcount++;
}

//Columns
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
       arraytemp[j] = grid[j][i]; //scanning each column to the temp. array for checking
    }
    colscheck = checkarray();
        if(colscheck == 1) //if method comes back true then column is unique
            colscount++;
}

//Nonettes
m=0; //starting position in the temporary array
    //i & j detirmine which 3x3 is being scanned in
for(i=0; i<9; i+=3){
    for(j=0; j<9; j+=3){
    //k and l loop through each 3x3
        for(k=i; k<i+3; k++){
            for(l=j; l<j+3; l++){
                arraytemp[m] = grid [l][k]; //m puts numbers in order in temp array for checking
                m++;
            }
        }
            noncheck = checkarray();
                if(noncheck == 1) //if method comes back true then 3x3 is unique
                    noncount++;
            m=0; // reset temp array after every 3x3 is checked
    }
}

//YES or NO
if(rowcount == 9 && colscount == 9 && noncount == 9) //to be a solved puzzle all 9 rows, columns and nonettes must be unique
    printf("YES\n");
else
    printf("NO\n");
}
    return 0;
}

int checkarray(){
int i, k, counter=0;
for(k=1; k<10; k++){ //loop through numbers 1-9 for checking
for(i=0; i<9; i++){
    if(arraytemp[i] == k) // check instances of each number seperately and add to counter for each instance
        counter++;
}
if(counter == 1){ // if only one instance array remains valid and counter is reset for next number to check
    counter=0;
}
else
    return 0; //method returns false if more than one instance of the same number
}
return 1; // method returns false if one instance of each number
}
















