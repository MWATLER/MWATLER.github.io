//Statistics.h - class declaration for statistics

class Statistics {
	double* data{ nullptr };
	int numData{ 0 };
	char* filename{ nullptr };
	unsigned precision;
	double average;
	double standardDeviation;
	void getNumData();
public:
	Statistics(const char* filename, unsigned precision = 4);
	Statistics(const Statistics&);
	Statistics& operator=(const Statistics&);
	void loadData();
	double GetAverage();
	double GetStandardDeviation();
	void PrintReport();
	~Statistics();
};