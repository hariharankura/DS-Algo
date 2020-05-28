#include <stddef.h>

#include "bitmagic.c"

#define SIZE_OF(s) (char*)(&s + 1) - (char*)&s


int (*hari_bit_fun[])(int) = {count_set_bits, check_even_odd, check_pow_2, calculate, set_bit_position};

typedef struct emp_ {
    char emp_name[30];
    unsigned int emp_id;
    unsigned int age;
    struct emp_ *mgr;
    float salary;
} emp_t;


typedef struct _student {
    char stud_name[32];
    int rollno;
    int age;
} student_t;

/*------------------------------------------------------*/
//this is a driver function
int main(){
	int number=58;
	print_bits(number);
	int r = hari_bit_fun[1](number);
    printf("check_even_odd:%d\n\n", r);

    emp_t emp;
    student_t st;

    printf("sizeof emp_name: %d offsetof emp_name: %d\n",sizeof(emp.emp_name), offsetof(emp_t, emp_name));
    printf("sizeof emp_id: %d offsetof emp_id: %d\n",sizeof(emp.emp_id), offsetof(emp_t, emp_id));
    printf("sizeof age: %d offsetof age: %d\n",sizeof(emp.age), offsetof(emp_t, age));
    printf("sizeof mgr: %d offsetof mgr: %d\n",sizeof(emp.mgr), offsetof(emp_t, mgr));
    printf("sizeof salary: %d offsetof salary: %d\n\n",sizeof(emp.salary), offsetof(emp_t, salary));

    printf("sizeof stud_name: %d offsetof stud_name: %d\n",sizeof(st.stud_name), offsetof(student_t, stud_name));
    printf("sizeof rollno: %d offsetof rollno: %d\n",sizeof(st.rollno), offsetof(student_t, rollno));
    printf("sizeof age: %d offsetof age: %d\n\n",sizeof(st.age), offsetof(student_t, age));

    double a;
    printf("my own sizeof function bytes of double: %d ",SIZE_OF(a));
    

	return 1;
}