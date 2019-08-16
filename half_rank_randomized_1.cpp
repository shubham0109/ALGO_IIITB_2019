
// find a no. with rank less than n/2 (n = 1million)
// randomized algo takes less than 20 comparisons (usually 4 or less)
// in this case we took first 1 million nos. and inserted it into array

# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;


int main(){
	srand(time(NULL));
	int arr[1000000];

	for (int i = 0; i < 1000000; i++){
		arr[i] = i+1;
	}
	
	int no_of_comparisons = 0;

	while(true){
		int random_index = rand()%1000000;
		no_of_comparisons++;
		cout<<"random index: "<<random_index<<endl;
		if (arr[random_index] < 500000){
			break;
		}
	}

	cout<<"NO. OF COMPARISONS: "<<no_of_comparisons<<endl;

	return 0;
}
