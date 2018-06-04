#ifndef HELPER_H
#define HELPER_H

int GCD(int a, int b)
{
	/*
		GCD(54,32)
		54 = 32*1 + 22
		32 = 22*1 + 10
		22 = 10*2 + 2
		10 = 2*5
	*/
		int num1,num2;
		if(a > b) {
			num1 = a;
			num2 = b;
		}
		else {
			num1 = b;
			num2 = a;	
		}
	
		while(num1%num2 != 0){
			int temp = num1%num2;			
			num1 = num2;			
			num2 = temp;
		}		
		return num2;
}

int LCM(int a, int b)
{
	/*	
		LCM = a*b / gcd(a,b)
	*/
	return (a*b)/GCD(a,b);
}
#endif
