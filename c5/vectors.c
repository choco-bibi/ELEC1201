//again, not everything

Vector createVector(const unsigned int nLength)
{
	Vector vec;
	vec.length = nLength;
	vec.element = (double*) calloc(vec.length, sizeof(double));
	return vec;
}

void destroyVector(Vector vec)
{
	free(vec.element);
}

void printVector(const Vector vec)
{
	unsigned int i;
	for (i=0; i<vec.length; i++)
		printf("[%d] = %lf\n", i, vec.element[i]);
}

int main(){
		Vector v;
		v=createVectorFromFile("example1.vec");
		printVector(v);
		destroyVector(v);
		return 0;
}	
