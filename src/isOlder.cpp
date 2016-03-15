/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.
ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isValid(int y,int m, int d){
	if (m < 1 || m > 12)
		return -1;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		if (d < 1 || d > 31)
			return -1;
		//else return 1;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11){
		if (d < 1 || d > 30)
			return -1;
		//else return 1;
	}
	if (m == 2){
		if ((y % 4 == 0) && (d <= 29))
			return 1;
		else if (d == 28)
			return 1;
		else
			return -1;
	}
	
}

int length(char *dob){
	int i = 0;
	while (*(dob + i) != '\0')
		i++;
	return i;
}

int isOlder(char *dob1, char *dob2) {
	int y1 = 0, y2 = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0, i = 0, l1, l2;
	l1 = length(dob1);
	l2 = length(dob2);
	if (l1 != 10 || l2 != 10){
		return -1;
	}
	while (*(dob1 + i) != '-' && *(dob2 + i) != '-'){
		d1 = (d1 * 10) + (dob1[i] - '0');
		d2 = (d2 * 10) + (dob2[i] - '0');
		i++;
	}
	i++;	
	while (*(dob1 + i) != '-' && *(dob2 + i) != '-'){
		m1 = (m1 * 10) + (dob1[i] - '0');
		m2 = (m2 * 10) + (dob2[i] - '0');
		i++;
	}
	i++;
	while (*(dob1 + i) != '\0'&& *(dob2 + i) != '\0'){
		y1 = (y1 * 10) + (dob1[i] - '0');
		y2 = (y2 * 10) + (dob2[i] - '0');
		i++;
	}
	if ((isValid(y1, m1, d1)) == -1 || (isValid(y2, m2, d2)) == -1)
		return -1;
	if (y1 > y2){
		return 2;
	}
	else if (y1 < y2)
		return 1;
	else if (y1 == y2){
		if (m1 > m2)
			return 2;
		else if (m1 < m2)
			return 1;
		else if (m1 == m2){
			if (d1 > d2)
				return 2;
			else if (d1 < d2)
				return 1;
			else
				return 0;	
		}
		
	}
}
