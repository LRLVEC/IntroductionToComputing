#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <new>

struct Student
{
	char id[11];
	char name[11];
	int age;
	char sex;
	double homeworkGrade;
	double midExamGrade;
	double practiceGrade;
	double finalExamGrade;
	double finalGrade;

	Student()
	{
		for (unsigned int c0(0); c0 < 10; ++c0)
			id[c0] = name[c0] = ' ';
		id[10] = name[10] = 0;
		scanf("%s%s%u %c%lf%lf%lf%lf", id, name, &age, &sex,
			&homeworkGrade, &midExamGrade, &practiceGrade, &finalExamGrade);
		unsigned int t(0);
		while (id[++t]); id[t] = ' ';
		t = 0;
		while (name[++t]); name[t] = ' ';
		getFinalGrade();
	}
	void getFinalGrade()
	{
		finalGrade = 0.15 * (homeworkGrade + midExamGrade) +
			0.1 * practiceGrade + 0.6 * finalExamGrade;
	}
	void print()const
	{
		printf("%s%s%2u %c%7.2lf", id, name, age, sex, finalGrade);
	}
	bool operator<(Student const& a)const
	{
		//fuck, must be fabs rather than abs
		if (fabs(finalGrade - a.finalGrade) < 1.0e-4)
		{
			unsigned int d(0);
			while (d < 10)
			{
				if (id[d] < a.id[d])return true;
				else if (id[d] > a.id[d])return false;
				else d++;
			}
			return false;
		}
		else return finalGrade > a.finalGrade;
	}
};

int main()
{
	unsigned int n(0);
	scanf("%u\n", &n);
	Student* students((Student*)malloc(n * sizeof(Student)));
	for (unsigned int c0(0); c0 < n; ++c0)
		new(students + c0)Student();
	std::sort(students, students + n);
	unsigned int lastFemalePos(0);
	for (unsigned int c0(0); c0 < n; ++c0)
	{
		if (students[c0].sex == 'F')lastFemalePos = c0;
		students[c0].print();
		printf("\n");
	}
	printf("\n");
	for (unsigned int c0(0); c0 < lastFemalePos; ++c0)
	{
		if (students[c0].sex == 'F')
		{
			students[c0].print();
			printf("\n");
		}
	}
	students[lastFemalePos].print();
	free(students);
}