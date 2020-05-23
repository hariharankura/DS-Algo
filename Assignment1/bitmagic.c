#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>



/*------------------------------------------------------*/
//print bit pattern
void print_bits(int number){
	
	int bits=(sizeof(number) * 8); //bytes->bits
	for(int i=bits-1;i>-1;i--){	
		if((i+1) && (i+1)%4==0){
			printf(" ");
		}
		printf(((number&1<<i)==0?"0":"1"));
	}	
	printf("\n");
}

/*1. -----------------------------------------------------*/
//count the total number of set bits in a number
int count_set_bits(int number){
	int count=0;
	while(number != 0){
		number = number & (number-1);
		count++;
	}
	return count;
}

/*2. -----------------------------------------------------*/
//check if the number is even or odd
int check_even_odd(int number){
	int return_val;
	if(number == 0){
		return_val = 0;
	}else{
		if(number & 1){
			return_val = -1;
		}else{
			return_val = 1;
		}
	}
	return return_val;
//return 0 for 0 and 1 for even and -1 for odd.
}


/*3. -----------------------------------------------------*/
//swap upper and lower 16 bits in 32 bit number
uint32_t swap_bytes(uint32_t number){
	return (number >> 16)|(number << 16);
//retrun the swapped number
}

/*4 . -----------------------------------------------------*/
//check for Endianness
void check_endian(){
	int num = 1;
	char *c = (char*)(&num);
	if(*c){
		printf("little endian\n");
	}else{
		printf("big endian\n");
	}
}

/*5. ------------------------------------------------------*/
//check for pow of 2
int check_pow_2(int number){
	int return_val = 0;
	if(number & (number-1)){
		return_val = 0;
	}else{
		return_val = 1;
	}
	return return_val;
//return 1 if true else retun 0
}




// /*6. ------------------------------------------------------*/
//Rotate a number || try in place rotation
uint32_t rotate(uint32_t number){
 number = (number>>16) | (number<<16);
 number = ((number & 0x00ff00ff) << 8) | ((number & 0xff00ff00) >> 8);
 number = ((number & 0x0f0f0f0f) << 4) | ((number & 0xf0f0f0f0) >> 4);
 number = ((number & 0x33333333) << 2) | ((number & 0xcccccccc) >> 2);
 number = ((number & 0x55555555) << 1) | ((number & 0xaaaaaaaa) >> 1);
 return number;
}

/*7. ------------------------------------------------------*/
//return (number x 8) + (number / 4) without using * and / operators
int calculate(int number){
 	return (number<<3) + (number>>2);
}

// /*8. ------------------------------------------------------*/
// generate a masks for q number of bits starting at bit position p 
int geneate_mask(int q, int p ){
 return (~((~0)<<q))<<p;
 //return result 
}


/*9. ------------------------------------------------------*/
// return bit position of first set bit from left
int set_bit_position(int number){
 number = number & ~(number-1);
 return log2(number)+1;
 //return result 
}
/*------------------------------------------------------*/


/*------------------------------------------------------*/
//this is a driver function
int main(){
	int number=567;
	print_bits(number);
	uint32_t num = 0x87F47689;
	printf("%x",rotate(0xaaaa5555));
	return 1;
}