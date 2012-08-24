#include "Structs.h"
#include "individual.h"
#include <vector>

using namespace std;

class firm{
    private:
        vector <individual*> employees;
        double productivity;
        product companyproduct;
    public:
        firm();
};
