// function prototype, declaration (in header files)
typedef struct {
	double real;
	double image;
} Cplex;

Cplex complexOperation(Cplex, Cplex, char);
void printComplex(Cplex[]);
char positive(double);