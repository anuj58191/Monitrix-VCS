#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <stdint.h>
#define MAX 200

int maximum(int x, int y); 

void lcs(char *X, char *Y, int ctr) {

	int m = strlen(X); 
	int n = strlen(Y); 
	int L[m+1][n+1];

	for (int i=0; i<=m; i++) { 
		for (int j=0; j<=n; j++) { 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (X[i-1] == Y[j-1]) 
				L[i][j] = L[i-1][j-1] + 1; 
			else L[i][j] = maximum(L[i-1][j], L[i][j-1]); 
		} 
	}

	int ix = L[m][n]; 
  
	char lcs[ix+1]; 
	char addition[m];
	char deletion[n];
	lcs[ix] = '\0';

	//Initializing variable sized character array named addition 
	for (int i = 0; i < m; ++i) {
		addition[i] = '0';
	}
	
	//Initializing variable sized character array named deletion
	for (int i = 0; i < n; ++i) {
		deletion[i] = '0';
	}
  
	int i = m, j = n; 
	while (i > 0 && j > 0) { 
  		if (X[i-1] == Y[j-1]) {
			lcs[ix-1] = X[i-1];
			i--; 
			j--; 
			ix--;
			//printf("%c", lcs[ix-1]);   
		} 
		else if (L[i-1][j] > L[i][j-1]) {
			//printf("At line %d :", ctr);
			//printf("\033[1;32m%c\033[0m", X[i-1]);
			addition[i-1] = X[i-1];  // Including the given character in addition
			i--;
			//printf("\n"); 
		}
		else {
			//printf("At line %d :", ctr);
			//printf("\033[1;31m%c\033[0m", Y[j-1]);
			deletion[j-1] = Y[j-1];  // Including the given character in deletion
			j--;
			// printf("\n"); 
		}
	}
	//printf("At line %d :", ctr);

	int q = 0;
	int r = 0;

	 for (int i = 0; i < m; ++i) {
	 	//printf("At line %d :", ctr);
	 	if (addition[i] != '0') {
	 		if (r == 0) {
	 			printf("At line %d :", ctr);
	 			//printf("%s", lcs);
	 			r++;
	 		}
	 		printf("\033[1;32m%c\033[0m",addition[i]);
	 	}
	}

	//printf("%s\n", lcs);

	int p = 0;
	for (int i = 0; i < n; ++i) {
		//printf("\nAt line %d :", ctr);
		if (deletion[i] != '0') {
			if (p == 0) {
			printf("\nAt line %d :", ctr);
			p++;
		}
			printf("\033[1;31m%c\033[0m",deletion[i]);
		}
	}




   //Printing the lcs

	if (q == 0) {
	 			printf("\nAt line %d :", ctr);
	 			printf("%s\n", lcs);
	 			q++;
	 		}
}

int maximum(int x, int y) {
	return (x > y) ? x : y;
} 
   
void openfiles(char file1, char file2) { 
  FILE *ptr1, *ptr2;
	char file[100];

	printf("Enter the filename to open for reading:"); 
    	scanf("%s", file1); 

	ptr1 = fopen(file1, "r");
	if (ptr1 == NULL) {
		printf("Cannot open file \n");
		exit(0);
	} 

	printf("Enter the second filename to open for reading:"); 
    	scanf("%s", file2); 

	ptr2 = fopen(file2, "r");
	if (ptr2 == NULL) {
		printf("Cannot open file \n");
		exit(0);
	} 

	char str1[MAX];
	char str2[MAX];

	char c;
	int count1 = 1, count2 = 1;

	for (c = getc(ptr1); c != EOF; c = getc(ptr1))  {
        if (c == '\n') 
            count1 = count1 + 1; 
	}

    for (c = getc(ptr2); c != EOF; c = getc(ptr2)) {
        if (c == '\n') 
            count2 = count2 + 1; 
    }

    rewind(ptr1);
    rewind(ptr2);

	int ctr = 1;

	while ((fgets (str1, MAX, ptr1)!= NULL) && (fgets (str2, MAX, ptr2)!=NULL)) {
		lcs(str1, str2, ctr);
		ctr++;
		//printf("\n");
	}

	rewind(ptr1);
    rewind(ptr2);
    
    int cmt = 0;

	if (count1 > count2) {
		printf("%d\n", count1);
		printf("Hello");
		printf("%d\n", count2);
		char line[500]; /* or other suitable maximum line size */
        while (fgets(line, sizeof line, ptr1) != NULL) /* read a line */{
            if (cmt > count23
            	)
            {   
                //use line or in a function return it
                //            //in case of a return first close the file with "fclose(file);"
            printf("\n %s ", line);
            }   
            else
            {   
                cmt++;
            }   
        } 
	} else if (count2 > count1) {
		printf("%d\n", count1);
		printf("%d\n", count2);
		char line[500]; /* or other suitable maximum line size */
        while (fgets(line, sizeof line, ptr2) != NULL) /* read a line */{
            if (cmt > count1)
            {   printf("%d\n", cmt);
                //use line or in a function return it
                //            //in case of a return first close the file with "fclose(file);"
            printf("\n %s ", line);
            }   
            else
            {   
                cmt++;
            }   
        }
	}
	else printf("%s\n");
	
	fclose(ptr1);
	fclose(ptr2); 
} 