#include <iostream>

using namespace std;

struct Address
{
  int pincode;
  char city[30];
  char state[30];
  char country[30];
};

struct Students
{
  int id;
  char name[100];
  char grade;
  struct Address address;
};

int main()
{

  int n = 1;

  printf("Enter the number of students: \n");
  scanf("%d", &n);

  struct Students students[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter the details of the students %d\n", i + 1);
    printf("Id: ");
    scanf("%d", &students[i].id);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Grade: ");
    scanf(" %c", &students[i].grade);
    printf("PinCode: ");
    scanf(" %d", &students[i].address.pincode);
    printf("City: ");
    scanf(" %s", students[i].address.city);
    printf("State: ");
    scanf(" %s", students[i].address.state);
    printf("Country: ");
    scanf(" %s", students[i].address.country);
  }

  printf("\n------ Student List -----\n");
  for (int i = 0; i < n; i++)
  {
    printf("Id: %d, Name: %s, Grade: %c, Pincode: %d, City: %s, State: %s, Country: %s\n", students[i].id, students[i].name, students[i].grade, students[i].address.pincode, students[i].address.city, students[i].address.state, students[i].address.country);
  }
  return 0;
}