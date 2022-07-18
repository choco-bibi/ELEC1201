//structures 

typedef enum {
	resistor,
	voltage,
	current,
} CompType;

typedef struct {
	CompType type;
	char name[32];
	unsigned int n1;
	unsigned int n2;
	double value;
} Component;

typedef struct {
	unsigned int nR;
	unsigned int nV;
	unsigned int nI;
	unsigned int nC;
	unsigned int nN;
	Component *comp;
} Circuit;
