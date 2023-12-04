#include "serialize_sanity.h"

typedef struct {
    int id;
    char *name;
    float gpa;
} Student;

void serialize_student(void *ptr, char *buf){
    Student *student = (Student *)ptr;
    memcpy(buf, &(student->id), sizeof(int));
    memcpy(buf + sizeof(int), student->name, strlen(student->name) + 1); 
    memcpy(buf + sizeof(int) + strlen(student->name) + 1, &(student->gpa), sizeof(float)); 
}

void deserialize_student(void *ptr, char *buf){
    Student *student = (Student *)ptr;
    memcpy(&(student->id), buf, sizeof(int)); 
    student->name = malloc(strlen(buf + sizeof(int)) + 1); 
    strcpy(student->name, buf + sizeof(int)); 
    memcpy(&(student->gpa), buf + sizeof(int) + strlen(student->name) + 1, sizeof(float));
}

void dump_student(void *ptr) {
    Student *student = (Student *) ptr;
    printf("Student: %d %s %f\n", student->id, student->name, student->gpa);
}

int compare_student(void *ptr1, void *ptr2) {
    Student *student1 = (Student *) ptr1;
    Student *student2 = (Student *) ptr2;
    if (student1->id != student2->id) return -1;
    if (strcmp(student1->name, student2->name) != 0) return -1;
    if (student1->gpa != student2->gpa) return -1;
    return 0;
}

int main() {
    Student student = {123456, "John Doe", 3.7};
    serialize_sanity(serialize_student, deserialize_student, dump_student, compare_student, &student, sizeof(student), 1);
    return 0;
}
