#include <iostream>
#include <algorithm>
using namespace std;
class Item{
public:
	int value, weight;
	Item(int value, int weight){
		this->value=value;
		this->weight=weight;
	}
};
bool cmp(Item x, Item y){
	double r1=(double)x.value/x.weight;
	double r2=(double)y.value/y.weight;
	return r1>r2;
}
void sorted(Item a[], int n, int wt){
		sort(a, a+n, cmp);
		double dol=0;
		int we=0;
		for(int i=0;i<n;i++){
			if(a[i].weight+we<wt){
				dol+=a[i].value;
				we+=a[i].weight;
			}else{
				int temp_weight=wt-we;
				dol+=((double)temp_weight/(a[i].weight))*(a[i].value);
				break;
			}
		}
		cout << "dol: " << dol << "->" << we << endl;
	}
int main(){

	Item a[]={{60, 10}, {100, 20}, {120, 30}};
	int wt=50;
	sorted(a, 3, wt);
	return 0;
}
